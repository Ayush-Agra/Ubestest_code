#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int func(vector<int>& arr,int l,int r){
  int cnt=0;
  vector<vector<int>> dp(arr.size()/2);
  for(int i=l;i<=r;i++){
    dp[arr[i]].push_back(i);
    // cout<<arr[i]<<" gfh "<<i<<endl;
  }
  for(int i=l;i<=r;i++){
    // cout<<i<<endl;
    int st=dp[arr[i]][0];int end=dp[arr[i]][1];
    stack<pair<int,int>> stk;
    stk.push({st,end});
    while(stk.size()>0){
      pair<int,int> ele=stk.top();
      stk.pop();
      int nwst=ele.first;int nwend=ele.second;
      // cout<<nwst<<" "<<nwend<<endl;
      for(int i=ele.first;i<=ele.second;i++){
        nwst=min(nwst,dp[arr[i]][0]);
        nwend=max(nwend,dp[arr[i]][1]);
      }
      if(nwst<st){
        stk.push({nwst,ele.first-1});
        st=nwst;
      }
      if(nwend>end){
        stk.push({ele.second+1,nwend});
        end=nwend;
      }
    }
    if(st==l && end==r)cnt+=1;
  }
  return cnt;
}
int32_t main(){
  fastio();
  int tc;cin>>tc;
  while(tc--){
    int n;cin>>n;
    int mod=998244353;
    vector<int> arr(2*n);
    for(int i=0;i<2*n;i++){cin>>arr[i];arr[i]-=1;}
    vector<int> flg(n,0);
    stack<int> stk;
    flg[arr[0]]=1;
    int cnt=1;int l=0;
    int ans=0;
    stk.push(arr[0]);
    for(int i=1;i<(2*n);i++){
      if(stk.size()!=0 && flg[arr[i]])stk.pop();
      if(flg[arr[i]]==0){stk.push(arr[i]);flg[arr[i]]=1;}
      if(stk.size()!=0)continue;
      // cout<<l<<" st "<<i<<endl;
      cnt=(cnt*func(arr,l,i))%mod;
      l=i+1;ans+=1;
    }
    cout<<ans<<" "<<cnt<<"\n";
  }
}