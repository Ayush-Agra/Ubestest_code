#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int gcd(int a, int b){
  return b == 0 ? a : gcd(b, a % b);   
}
int32_t main(){
  fastio();
  int n;cin>>n;
  vector<int> arr(n);
  int mx=0;
  for(int i=0;i<n;i++){cin>>arr[i];mx=max(mx,arr[i]);}
  vector<int> vec(mx+1,0);
  for(int i=0;i<n;i++){
    vec[arr[i]]=1;
  }
  int oper=0;
  for(int i=1;i<=mx;i++){
    int x=0;
    for(int j=i;j<=mx;j+=i){
      if(vec[j]) x=gcd(x,j);
    }
    if(x==i) oper+=1;
  }
  cout<<oper-n;
}