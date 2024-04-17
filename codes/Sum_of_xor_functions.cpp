#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int mod=998244353;
int n;
int func(vector<int>& arr){
  vector<vector<int>> dp(n,{0,0,-1,-1});
  int cnt=0;
  if(arr[0]==1){
    dp[0][0]=1;dp[0][1]=1;dp[0][2]=0;
  }else{
    cnt+=1;
  }
  for(int i=1;i<n;i++){
    if(arr[i]){
      cnt+=1;
      dp[i][0]=(cnt*(cnt+1))/2;
      dp[i][0]%=mod;
      if(dp[i-1][3]==-1){
        dp[i][3]=dp[i-1][2];
        dp[i][2]=i;
        dp[i][1]=cnt;
        dp[i][1]%=mod;
      }else{
        dp[i][0]+=dp[dp[i-1][3]][0]+dp[dp[i-1][3]][1]*(i-dp[i-1][3]);
        dp[i][0]%=mod;
        dp[i][1]=cnt+dp[dp[i-1][3]][1];
        dp[i][3]=dp[i-1][2];
        dp[i][2]=i;
        dp[i][1]%=mod;
      }
      cnt=0;
      continue;
    }
    cnt+=1;
    if(dp[i-1][2]!=-1){
      dp[i][0]=dp[i-1][0]+dp[i-1][1];
      dp[i][0]%=mod;
      dp[i][1]=dp[i-1][1];
      dp[i][2]=dp[i-1][2];
      dp[i][3]=dp[i-1][3];
    }
  }
  int ans=0;
  for(int i=0;i<n;i++){
    ans+=dp[i][0];
    ans%=mod;
  }
  return ans;
}
int32_t main(){
  fastio();
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i];
  int ans=0;
  for(int i=0;i<31;i++){
    int val=1<<i;
    vector<int> temp(n);
    for(int j=0;j<n;j++){
      int nm=(arr[j]>>i)%2;
      temp[j]=nm;
    }
    int num=func(temp);
    ans+=((val*num)%mod);
    ans%=mod;
  }
  cout<<ans<<"\n";
}