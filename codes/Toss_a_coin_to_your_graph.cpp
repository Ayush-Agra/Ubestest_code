#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int k;int mid;int n;
void dfs(vector<vector<int>>& edges,int leaf,vector<int>& dp,vector<int>& vis,vector<int>& arr){
  vis[leaf]=1;
  for(int i=0;i<edges[leaf].size();i++){
    if(vis[edges[leaf][i]]==1){vis[n]=1;return;}
    if(arr[edges[leaf][i]]>mid) continue;
    if(dp[edges[leaf][i]]!=0){
      dp[leaf]=max(dp[edges[leaf][i]],dp[leaf]);
      continue;
    }
    dfs(edges,edges[leaf][i],dp,vis,arr);
    if(vis[n]==1) return;
    dp[leaf]=max(dp[edges[leaf][i]],dp[leaf]);
  }
  vis[leaf]=-1;
  dp[leaf]+=1;
  if(dp[leaf]>=k) vis[n]=1;
}
int32_t main(){
  int m;
  cin>>n>>m>>k;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  vector<vector<int>> edges(n);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a-=1;b-=1;
    edges[a].push_back(b);
  }
  int l=1;
  int r=1e9;
  while(l<=r){
    vector<int> dp(n,0);
    vector<int> vis(n+1,-1);
    mid=l+(r-l)/2;
    for(int i=0;i<n;i++){
      if(dp[i]!=0 || arr[i]>mid) continue;
      dfs(edges,i,dp,vis,arr);
      if(vis[n]==1) break;
    }
    if(vis[n]==1) r=mid-1;
    else l=mid+1;
  }
  if(r==1e9) r=-2;
  cout<<r+1;
}