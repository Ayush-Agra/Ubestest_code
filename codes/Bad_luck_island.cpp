#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
void dfs(vector<vector<vector<vector<double>>>>& dp,double r,double s,double p){
  if(r==0){
    dp[r][s][p]={0,1,0};return;
  }if(s==0){
    dp[r][s][p]={0,0,1};return;
  }else if(p==0){
    dp[r][s][p]={1,0,0};return;
  }
  if(dp[r][s][p].size()>0)return;
  double sm=r*s+s*p+p*r;
  vector<double> pro(3);
  vector<double> prol(3);
  pro[0]=(r*s)/sm;
  pro[1]=(s*p)/sm;
  pro[2]=(p*r)/sm;
  dfs(dp,r-1,s,p);
  dfs(dp,r,s-1,p);
  dfs(dp,r,s,p-1);
  dp[r][s][p]={0,0,0};
  for(int i=0;i<3;i++){
    dp[r][s][p][i]+=pro[0]*dp[r][s-1][p][i];
    dp[r][s][p][i]+=pro[1]*dp[r][s][p-1][i];
    dp[r][s][p][i]+=pro[2]*dp[r-1][s][p][i];
  }
}
int32_t main(){
  fastio();
  cout<<setprecision(14);
  int r,s,p;
  cin>>r>>s>>p;
  vector<vector<vector<vector<double>>>> dp(r+1,vector<vector<vector<double>>>(s+1,vector<vector<double>>(p+1)));
  dfs(dp,r,s,p);
  cout<<dp[r][s][p][0]<<" "<<dp[r][s][p][1]<<" "<<dp[r][s][p][2]<<"\n";
}