#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int32_t main(){
  fastio();
  string s,t;
  cin>>s>>t;
  int n,m;
  n=s.length();m=t.length();
  vector<vector<int>> dp(n+1,vector<int>(n+1,0));
  int mod=998244353;
  for(int i=0;i<=n;i++)dp[0][i]=1;
  for(int i=0;i<n;i++){
    for(int j=0;j<=n;j++){
      if(dp[i][j]==0)continue;
      if(i+j<=n){
        if(i+j<m && s[i]==t[i+j]){
          dp[i+1][j]+=dp[i][j];
          dp[i+1][j]%=mod;
        }else if(i+j>=m && i+j<n){
          dp[i+1][j]+=dp[i][j];
          dp[i+1][j]%=mod;
        }
      }
      if(j>0){
        if(j<=m && s[i]==t[j-1]){
          dp[i+1][j-1]+=dp[i][j];
          dp[i+1][j-1]%=mod;
        }else if(j>m){
          dp[i+1][j-1]+=dp[i][j];
          dp[i+1][j-1]%=mod;
        }
      }
    }
  }
  int ans=0;
  for(int i=m;i<=n;i++){
    ans+=dp[i][0];
    ans%=mod;
  }
  cout<<ans<<"\n";
}