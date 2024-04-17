#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int modInverse(int A, int M)
{
    int m0 = M;
    int y = 0, x = 1;
 
    if (M == 1)
        return 0;
 
    while (A > 1) {
        // q is quotient
        int q = A / M;
        int t = M;
 
        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}
vector<int> pr(1e6+1,-1);
void sieve(){
  int nm=1e6;
  pr[0]=0;pr[1]=1;
  for(int i=2;i*i<=nm;i++){
    if(pr[i]!=-1) continue;
    for(int j=i*i;j<=nm;j+=i){
      if(pr[j]!=-1) continue;
      pr[j]=i;
    }
  }
}
int32_t main(){
  fastio();
  sieve();
  int n;cin>>n;
  map<int,int> prime;
  map<int,int> comp;
  vector<int> modinv(2*n+1);
  int mod=998244353;
  modinv[1]=1;
  for(int i=2;i<=2*n;i++){
    modinv[i]=(modinv[i-1]*modInverse(i,mod))%mod;
  }
  for(int i=0;i<2*n;i++){
    int a;cin>>a;
    if(pr[a]==-1){
      if(prime.find(a)==prime.end()) prime[a]=1;
      else prime[a]+=1;
    }else{
      if(comp.find(a)==comp.end()) comp[a]=1;
      else comp[a]+=1;
    }
  }
  if(prime.size()<n){
    cout<<0;
    return 0;
  }
  int ans=1;
  vector<int> arr;
  for(int i=2;i<=n;i++) ans=(ans*i)%mod;
  for(auto x:prime){
    ans=(ans*modinv[x.second])%mod;
    arr.push_back(x.second);
  }
  for(auto x:comp){
    ans=(ans*modinv[x.second])%mod;
  }
  vector<int> prev(n+1,0);
  prev[0]=1;
  for(int i=0;i<arr.size();i++){
    vector<int> nxt(n+1,0);
    nxt[0]=1;
    for(int j=0;j<n;j++){
      nxt[j+1]=(prev[j]*arr[i]+prev[j+1])%mod;
    }
    prev=nxt;
  }
  ans=(ans*prev[n])%mod;
  cout<<ans;
}