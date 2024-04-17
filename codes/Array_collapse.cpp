#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int32_t main(){
  fastio();
  int tc;cin>>tc;
  while(tc--){
    int n;cin>>n;
    int mod=998244353;
    vector<int> arr(n);
    vector<int> pre(n+1,0);
    for(int i=0;i<n;i++)cin>>arr[i];
    stack<int> stk;
    int sm=0;
    for(int i=0;i<n;i++){
      while(stk.size()>0 && arr[stk.top()]>arr[i]){
        sm=(sm+mod-(pre[stk.top()+1]-pre[stk.top()]+mod)%mod)%mod;stk.pop();
      }
      int upto=0;
      if(stk.size()==0)pre[i+1]=1;
      else upto=stk.top()+1;
      // cout<<sm<<" "<<i<<" "<<upto<<endl;
      pre[i+1]+=pre[i]-pre[upto]+sm;
      pre[i+1]%=mod;
      sm+=pre[i+1];
      sm%=mod;
      pre[i+1]+=pre[i];
      pre[i+1]%=mod;
      stk.push(i);
    }
    cout<<(sm+mod)%mod<<"\n";
  }
}