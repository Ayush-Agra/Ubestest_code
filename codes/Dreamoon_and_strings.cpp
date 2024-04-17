#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int n,k;
int func(string& s,string& t,int st){
  int cur=0;
  for(int i=st;i<n;i++){
    if(s[i]==t[cur]){
      cur+=1;
      if(cur==t.size())return i;
    }
  }
  return -1;
}
int32_t main(){
  fastio();
  string s;cin>>s;
  string t;cin>>t;
  n=s.size();k=t.size();
  vector<int> sto(n);
  for(int i=0;i<n;i++){
    sto[i]=func(s,t,i);
  }
  vector<vector<int>> dp(n+1,vector<int>(n+1,0));
  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
      dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
      if(sto[i]!=-1)dp[sto[i]+1][j+sto[i]+1-i-k]=max(dp[sto[i]+1][j+sto[i]+1-i-k],dp[i][j]+1);
    }
  }
  for(int i=0;i<n+1;i++){
    cout<<dp[n][i]<<" ";
  }
}