#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int k;
void dfs(vector<vector<int>>& edges,int leaf,vector<int>& dp,vector<int>& arr){
  for(int i=0;i<edges[leaf].size();i++){
    if(dp[edges[leaf][i]]==-1) dfs(edges,edges[leaf][i],dp,arr);
    if(arr[leaf]>=(dp[edges[leaf][i]]%k)){
      dp[leaf]=max(dp[edges[leaf][i]]+(arr[leaf]-(dp[edges[leaf][i]]%k)),dp[leaf]);
    }else{
      dp[leaf]=max(dp[leaf],dp[edges[leaf][i]]+arr[leaf]+(k-(dp[edges[leaf][i]]%k)));
    }
  }
  if(dp[leaf]==-1){
    dp[leaf]=arr[leaf];
  }
}
void fdfs(vector<vector<int>>& edges,int leaf,vector<int>& dp,vector<int>& arr,vector<int>& mxi){
  if(edges[leaf].size()==0) mxi[0]=max(mxi[0],dp[leaf]);
  for(int i=0;i<edges[leaf].size();i++){
    int vl;
    if(arr[edges[leaf][i]]>=arr[leaf]){
      vl=dp[leaf]+(arr[edges[leaf][i]]-arr[leaf]);
    }else{
      vl=dp[leaf]+arr[edges[leaf][i]]+k-arr[leaf];
    }
    if(vl>dp[edges[leaf][i]]){
      dp[edges[leaf][i]]=vl;
      fdfs(edges,edges[leaf][i],dp,arr,mxi);
    }
  }
}
int32_t main(){
  fastio();
  int tc;cin>>tc;
  while(tc--){
    int n,m;
    cin>>n>>m>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<vector<int>> fedges(n);
    vector<vector<int>> bedges(n);
    for(int i=0;i<m;i++){
      int a,b;cin>>a>>b;
      a-=1;b-=1;
      fedges[a].push_back(b);
      bedges[b].push_back(a);
    }
    vector<int> dp(n,-1);
    int mx=0;
    for(int i=0;i<n;i++){
      if(dp[i]!=-1 || fedges[i].size()!=0) continue;
      dfs(bedges,i,dp,arr);
      mx=max(mx,dp[i]);
    }
    vector<pair<int,int>> vl;
    for(int i=0;i<n;i++){
      if(bedges[i].size()==0){
        vl.push_back({arr[i],i});
      }
    }
    sort(vl.begin(),vl.end());
    int mn=mx-vl[0].first;
    vector<int> mxi(1);
    mxi[0]=mx;
    for(int i=0;i<vl.size()-1;i++){
      dp[vl[i].second]+=k;
      int st=vl[i+1].first;
      fdfs(fedges,vl[i].second,dp,arr,mxi);
      mn=min(mn,mxi[0]-st);
    }
    cout<<mn<<"\n";
  } 
}