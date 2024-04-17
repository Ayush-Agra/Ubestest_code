#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int power(int x,int y,int p)
{
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}
int modinv(int a,int p){
  return power(a,p-2,p);
}
int32_t main(){
  fastio();
  int n;
  cin>>n;
  int mod=1e9+7;
  vector<pair<int,int>> arr(n);
  vector<int> pre(n,1);
  vector<int> suf(n,1);
  vector<int> sto(n);
  int tm=mod-1;
  int count=1;
  int sm=1;
  for(int i=0;i<n;i++){
    cin>>arr[i].first>>arr[i].second;
    count*=(arr[i].second+1);
    count%=mod;
    sto[i]=((power(arr[i].first,arr[i].second+1,mod)-1)*(modinv(arr[i].first-1,mod)))%mod;
    sm*=sto[i];
    sm%=mod;
  }
  vector<int> hl(n);
  pre[0]=arr[0].second+1;
  suf[n-1]=arr[n-1].second+1;
  for(int i=1;i<n;i++){
    pre[i]=(pre[i-1]*(arr[i].second+1))%tm;
    suf[n-i-1]=(suf[n-i]*(arr[n-i-1].second+1)%tm);
  }
  for(int i=0;i<n;i++){
    if(n==1) break;
    hl[i]=(arr[i].second)*(arr[i].second+1);
    hl[i]/=2;
    hl[i]%=tm;
    if(i==0){
      hl[i]=suf[i+1]*hl[i];
      hl[i]%=tm;
    }else if(i==n-1){
      hl[i]=pre[i-1]*hl[i];
      hl[i]%=tm;
    }else{
      hl[i]=pre[i-1]*hl[i];
      hl[i]%=tm;
      hl[i]=suf[i+1]*hl[i];
      hl[i]%=tm;
    }
  }
  if(n==1){
    hl[0]=(arr[0].second)*(arr[0].second+1);
    hl[0]/=2;
    hl[0]%=tm;
  }
  int ans=1;
  for(int i=0;i<n;i++){
    ans*=power(arr[i].first,hl[i],mod);
    ans%=mod;
  }
  cout<<count<<" "<<sm<<" ";
  cout<<ans<<"\n";
}