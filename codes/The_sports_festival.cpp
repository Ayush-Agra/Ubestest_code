#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int32_t main(){
  fastio();
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  sort(arr.begin(),arr.end());
  vector<vector<int>> dp(n,vector<int>(n,1e18));
  for(int i=0;i<n;i++) dp[i][i]=0;
  for(int i=1;i<n;i++){
    for(int j=i-1;j>=0;j--){
      dp[j][i]=min(dp[j+1][i],dp[j][i-1])+arr[i]-arr[j];
    }
  }
  cout<<dp[0][n-1]<<"\n";
}