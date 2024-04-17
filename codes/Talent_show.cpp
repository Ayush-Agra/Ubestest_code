#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int n,w;
vector<int> wei;
vector<int> tal;
bool solve(int y){
  vector<int> dp(w+1,-1e18);
  dp[0]=0;
  for(int i=0;i<n;i++){
    int vl=1000*tal[i]-y*wei[i];
    for(int j=w;j>=0;j--){
      if(dp[j]==-1e18)continue;
      dp[min(w,j+wei[i])]=max(dp[min(j+wei[i],w)],dp[j]+vl);
    }
  }
  return dp[w]>=0;
}
int32_t main(){
  freopen("talent.in", "r", stdin);
  freopen("talent.out", "w", stdout);
  cin>>n>>w;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    wei.push_back(a);
    tal.push_back(b);
  }
  int r=1000*1000;
  int l=0;
  while(l<=r){
    int mid=l+(r-l)/2;
    if(solve(mid)){
      l=mid+1;
    }else{
      r=mid-1;
    }
  }
  cout<<l-1<<"\n";
}