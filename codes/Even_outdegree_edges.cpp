#include <bits/stdc++.h>
using namespace std;
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
void dfs(vector<vector<pair<int,int>>>& edges,vector<vector<pair<int,int>>>& tree,vector<pair<int,int>>& sto,vector<int>& vis,vector<int>& cnt,int leaf,int root){
  vis[leaf]=1;
  for(int i=0;i<edges[leaf].size();i++){
    int v=edges[leaf][i].first;
    int ind=edges[leaf][i].second;
    if(v==root)continue;
    if(vis[v]==1){
      sto[ind]={leaf,v};
      cnt[leaf]+=1;continue;
    }else if(vis[v]==2)continue; 
    tree[leaf].push_back(edges[leaf][i]);
    tree[v].push_back({leaf,ind});
    dfs(edges,tree,sto,vis,cnt,v,leaf);
  }
  vis[leaf]=2;
}
void dfs2(vector<vector<pair<int,int>>>& edges,vector<pair<int,int>>& sto,vector<int>& cnt,int leaf,int root){
  for(int i=0;i<edges[leaf].size();i++){
    int v=edges[leaf][i].first;
    int ind=edges[leaf][i].second;
    if(v==root)continue;
    // cout<<v<<endl;
    // cout<<cnt[v]<<endl;
    dfs2(edges,sto,cnt,v,leaf);
    if(cnt[v]%2==0){sto[ind]={leaf,v};cnt[leaf]+=1;}
    else {sto[ind]={v,leaf};cnt[v]+=1;}
  }
}
int32_t main(){
  int n,m;cin>>n>>m;
  vector<pair<int,int>> sto(m);
  vector<vector<pair<int,int>>> edges(n);
  vector<vector<pair<int,int>>> tree(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a-=1;b-=1;
    sto[i]={a,b};
    edges[a].push_back({b,i});
    edges[b].push_back({a,i});
  }
  vector<int> vis(n,0);
  vector<int> cnt(n,0);
  for(int i=0;i<n;i++){
    if(vis[i])continue;
    dfs(edges,tree,sto,vis,cnt,i,-1);
    dfs2(tree,sto,cnt,i,-1);
  }
  for(int i=0;i<n;i++){
    if(cnt[i]%2==1){
      cout<<"IMPOSSIBLE\n";
      return 0;
    }
  }
  for(int i=0;i<m;i++){
    cout<<sto[i].first+1<<" "<<sto[i].second+1<<"\n";
  }
  cout<<"\n";
}