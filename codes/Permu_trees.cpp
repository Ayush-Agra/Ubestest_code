#include <bits/stdc++.h>
using namespace std;
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}

bitset<5004> nxt;
bitset<5004> pre;
int dfs(vector<vector<int>>& edges,int root,int leaf,vector<int>& sbtree){
  int sm=0;int ans=0;
  for(int i=0;i<edges[leaf].size();i++){
    ans+=dfs(edges,leaf,edges[leaf][i],sbtree);
    sbtree[leaf]+=sbtree[edges[leaf][i]];
  }
  pre.flip(0);
  for(int i=0;i<edges[leaf].size();i++){
    nxt=pre<<sbtree[edges[leaf][i]];
    nxt=pre | nxt;
    pre=nxt;
  }
  sm=sbtree[leaf];
  int mx=0;
  for(int i=0;i<sm;i++){
    if(nxt[i]){
      mx=max(mx,i*(sm-1-i));
    }
  }
  pre.reset();nxt.reset();
  return ans+mx;
}
int32_t main(){
  fastio();
  int n;
  cin>>n;
  vector<vector<int>> edges(n);
  for(int i=1;i<n;i++){
    int a;cin>>a;a-=1;
    edges[a].push_back(i);
  }
  vector<int> sbtree(n,1);
  int val=dfs(edges,-1,0,sbtree);
  cout<<val<<"\n";
}