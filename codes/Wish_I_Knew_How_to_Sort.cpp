#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int modInverse(int A, int M) { 
    int m0 = M; 
    int y = 0, x = 1; 
    if (M == 1) 
        return 0; 
    while (A > 1) {  
        int q = A / M; 
        int t = M; 
        M = A % M, A = t; 
        t = y;  
        y = x - q * y; 
        x = t; 
    }  
    if (x < 0) 
        x += m0; 
    return x; 
} 
int32_t main(){
  int tc;cin>>tc;
  while(tc--){
    int n;cin>>n;
    vector<int> arr(n);
    int cnt=0;
    for(int i=0;i<n;i++){cin>>arr[i];cnt+=arr[i];}
    cnt=n-cnt;
    vector<int> dp(cnt+1,-1);
    dp[cnt]=0;
    int mod=998244353;
    int deno=(n*(n-1));
    deno=modInverse(deno,mod);
    for(int i=cnt-1;i>=0;i--){
      int p=(2*((cnt-i)*(cnt-i))%mod)%mod;
      p=(p*deno)%mod;
      dp[i]=(1+p*dp[i+1])%mod;
      dp[i]=(dp[i]*modInverse(p,mod))%mod;
    }
    int nm=0;
    for(int i=0;i<cnt;i++){
      if(arr[i]==0)nm+=1;
    }
    cout<<dp[nm]<<"\n";
  }
}