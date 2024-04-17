#include <bits/stdc++.h>
using namespace std;
#define int long long
int dfs(vector<vector<int>>& edges,int leaf,int root,vector<int>& vis){
    int sm=0;
    for(int i=0;i<edges[leaf].size();i++){
        if(edges[leaf][i]==root) continue;
        vis[edges[leaf][i]]=1;
        sm+=dfs(edges,edges[leaf][i],leaf,vis);
    }
    sm+=1;
    return sm;
}

int32_t main() {
    int n;
    cin>>n;
    vector<vector<int>> edges(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a-=1;b-=1;
        char c;cin>>c;
        if(c=='r') continue;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int> vis(n,0);
    vector<int> cnt;
    for(int i=0;i<n;i++){
        if(vis[i]==1) continue;
        vis[i]=1;
        int ct=dfs(edges,i,-1,vis);
        cnt.push_back(ct);
    }
    int k=cnt.size();
    vector<int> pre(k);
    pre[k-1]=cnt[k-1];
    int mod=1e9+7;
    for(int i=k-2;i>=0;i--){
        pre[i]=pre[i+1]+cnt[i];
        pre[i]%=mod;
    }
    vector<int> nw(k);
    for(int i=k-2;i>0;i--){
        nw[i]=pre[i+1]*cnt[i];
        nw[i]%=mod;
    }
    for(int i=k-2;i>=1;i--){
        nw[i]=nw[i+1]+nw[i];
        nw[i]%=mod;
    }
    int sm=0;
    for(int i=0;i<k-2;i++){
        sm+=cnt[i]*nw[i+1];
        sm%=mod;
    }
    cout<<sm;
    return 0;
}