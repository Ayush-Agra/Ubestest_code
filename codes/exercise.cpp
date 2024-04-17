#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int32_t main(){
  freopen("exercise.in","r",stdin);
  freopen("exercise.out","w",stdout);
  int n,m;
  cin>>n>>m;
  vector<int> p;
  vector<int> comp(n+1,0);
  for(int i=2;i<=n;i++){
    if(comp[i]) continue;
    p.push_back(i);
    for(int j=i*i;j<=n;j+=i){
      comp[j]=1;
    }
  }
  int sm=0;
  vector<int> prev(n+1,0);
  prev[0]=1;
  for(int i=0;i<p.size();i++){
    int pp=p[i];
    for(int j=n;j>1;j--){
      while(pp<=j){
        prev[j]+=((prev[j-pp]*pp)%m);
        prev[j]%=m;
        pp=pp*p[i];
      }
      pp=p[i];
    }
  }
  for(int i=0;i<=n;i++){
    sm+=prev[i];
    sm%=m;
  }
  cout<<sm<<"\n";
}