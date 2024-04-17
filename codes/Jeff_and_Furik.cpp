#include <bits/stdc++.h>
#define int long long
using namespace std;
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int32_t main(){
  int n;cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  vector<int> p((n*(n-1)/2)+1);
  p[0]=0;p[2]=4;p[1]=1;
  for(int i=3;i<p.size();i++)p[i]=4+p[i-2];
  int inv=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(a[j]<a[i])inv+=1;
    }
  }
  cout<<p[inv]<<"\n";
}