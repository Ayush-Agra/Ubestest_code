#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
vector<int> func(vector<int>& arr,int l){
  stack<int> stk;
  vector<int> ans(arr.size(),0);
  for(int i=l;i<arr.size();i++){
    int cn=arr[i];
    while(stk.size()>0 && stk.top()==cn){
      cn=cn+1;
      stk.pop();
    }
    stk.push(cn);
    if(stk.size()==1)ans[i]=1;
  }
  return ans;
}
int32_t main(){
  int n;cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++)cin>>arr[i];
  vector<vector<int>> dp(n);
  for(int i=0;i<n;i++){
    dp[i]=func(arr,i);
  }
  vector<int> ans(n,1e9);
  for(int i=0;i<n;i++){
    if(dp[0][i]==1){ans[i]=1;continue;}
    for(int j=1;j<=i;j++){
      if(dp[j][i]==0)continue;
      ans[i]=min(ans[i],1+ans[j-1]);
    }
  }
  cout<<endl;
  cout<<ans[n-1]<<"\n";
}