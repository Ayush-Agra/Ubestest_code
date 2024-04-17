#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
const int inf=1e9;
bitset<400000> loop;
int dfs(vector<vector<int>>& edges,int par,int root,vector<int>& dp,vector<int>& vis,vector<int>& cyc){
  if(vis[root]==1){dp[root]=inf;return cyc[root];}
  if(dp[root]!=0) return inf;
  if(par==0 && root==0) dp[root]=1;
  else dp[root]=max(dp[root],dp[par]);
  cyc[root]=cyc[par]+1;int vl=inf;vis[root]=1;
  for(int i=0;i<edges[root].size();i++){
    if(dp[edges[root][i]]>1 && vis[edges[root][i]]==0) continue;
    if(dp[edges[root][i]]==1 && vis[edges[root][i]]==0){dp[edges[root][i]]=2;continue;}
    vl=min(vl,dfs(edges,root,edges[root][i],dp,vis,cyc));
    if(vl<=cyc[root]) dp[root]=inf;
  }
  vis[root]=0;cyc[root]=0;
  return vl;
}
void sec(vector<vector<int>>& edges,int root,vector<int>& dp,vector<int>& vis){
  if(vis[root]==1 || vis[root]==2)return;
  if(vis[root]==3 && dp[root]==2) return;
  vis[root]=1;
  for(int i=0;i<edges[root].size();i++){
    dp[edges[root][i]]=max(dp[edges[root][i]],dp[root]);
    sec(edges,edges[root][i],dp,vis);
  }
  if(dp[root]>2) vis[root]=2;
  else vis[root]=3;
}
int32_t main(){
  fastio();
  int tc;cin>>tc;
  while(tc--){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(n);
    for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      a-=1;b-=1;
      if(a==b){loop.set(a);continue;}
      edges[a].push_back(b);
    }
    vector<int> vis(n,0);
    vector<int> dp(n,0);
    vector<int> cyc(n,0);
    vis[0]=0;
    dfs(edges,0,0,dp,vis,cyc);
    for(int i=0;i<n;i++){
      if(dp[i]!=0 && loop[i]) dp[i]=inf;
    }
    sec(edges,0,dp,vis);
    for(int i=0;i<n;i++){
      if(dp[i]==inf) cout<<-1<<" ";
      else cout<<dp[i]<<" ";
    }
    cout<<"\n";
    loop.reset();
  }
}