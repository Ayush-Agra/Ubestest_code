#include <bits/stdc++.h>
#define int long long
using namespace std;
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int mod=1e9+7;
int32_t main(){
  setprecision(9);
  int n,x;
  cin>>n>>x;
  int vl=log2(n)+2;
  vector<vector<double>> dp(vl,vector<double>(128,0));
  for(int i=0;i<=x;i++)cin>>dp[0][i];
  for(int i=1;i<vl;i++){
    for(int j=0;j<128;j++){
      for(int k=0;k<128;k++){
        int v=j^k;
        // cout<<i<<" "<<j<<" "<<k<<" "<<v<<endl;
        dp[i][v]+=dp[i-1][j]*dp[i-1][k];
      }
    }
  }
  vector<double> ans(128,0);
  ans[0]=1;
  for(int i=0;i<vl;i++){
    vector<double> temp(128,0);
    if(n&(1<<i)){
      for(int j=0;j<128;j++){
        for(int k=0;k<128;k++){
          int v=j^k;
          temp[v]+=dp[i][j]*ans[k];
        }
      }
      ans=temp;
    }
  }
  cout<<1-ans[0]<<"\n";
}