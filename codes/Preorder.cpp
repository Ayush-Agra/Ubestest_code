#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int n;
int mod=998244353;
string func(string& s,vector<int>& dp,int leaf){
  if(leaf>=(1<<(n-1))){
    dp[leaf]=1;
    return s.substr(leaf-1,1);
  }
  string tx=func(s,dp,2*leaf);
  string ty=func(s,dp,2*leaf+1);
  if(tx==ty){
    dp[leaf]=(dp[2*leaf]*dp[2*leaf+1])%mod;
    return s[leaf-1]+tx+ty;
  }else{
    dp[leaf]=(2*dp[2*leaf]*dp[2*leaf+1])%mod;
    return min(s[leaf-1]+tx+ty,s[leaf-1]+ty+tx);
  }
}
int32_t main(){
  cin>>n;
  string s;cin>>s;
  vector<int> dp(s.size()+1,0);
  func(s,dp,1);
  cout<<dp[1]<<"\n";
}