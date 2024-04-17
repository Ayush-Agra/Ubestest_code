#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int32_t main(){
  fastio();
  int n,m;
  cin>>n>>m;
  string s;cin>>s;
  vector<vector<int>> lst(n,vector<int>(26,-1));
  lst[0][s[0]-'a']=0;
  for(int i=1;i<n;i++){
    for(int j=0;j<26;j++){
      lst[i][j]=lst[i-1][j];
    }
    lst[i][s[i]-'a']=i;
  }
  vector<vector<int>> dp(n,vector<int>(n,0));
  for(int i=0;i<n;i++)dp[i][0]=1;
  for(int i=1;i<n;i++){
    for(int j=1;j<n;j++){
      for(int k=0;k<26;k++){
        if(lst[i-1][k]==-1)continue;
        dp[i][j]+=dp[lst[i-1][k]][j-1];
      }
    }
  }
  int ans=0;
  for(int i=n-1;i>=0;i--){
    for(int j=0;j<26;j++){
      if(lst[n-1][j]==-1)continue;
      if(m>dp[lst[n-1][j]][i]){
        m-=dp[lst[n-1][j]][i];
        ans+=dp[lst[n-1][j]][i]*(n-i-1);
      }else{
        ans+=m*(n-i-1);
        cout<<ans;
        return 0;
      }
    }
  }
  if(m==1){
    cout<<ans+n;
  }else{
    cout<<-1;
  }
}