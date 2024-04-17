#include <bits/stdc++.h>
#define int double
using namespace std;
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int32_t main(){
  int n;cin>>n;
  vector<int> arr(n,0);
  vector<int> dp;
  for(int i=0;i<n-2;i++){
    int a;cin>>a;
    a-=1;arr[a]+=1;
    dp.push_back(a);
  }
  arr[n-1]+=1;
  set<int> uset;
  for(int i=0;i<n;i++){
    if(!arr[i])uset.insert(i);
  }
  vector<int> p(n,-1);
  for(int i=0;i<(n-2);i++){
    int a=*uset.begin();
    uset.erase(a);
    p[a]=dp[i];
    arr[dp[i]]-=1;
    if(!arr[dp[i]])uset.insert(dp[i]);
  }
  for(int i=0;i<n-1;i++){
    if(p[i]==-1)p[i]=n-1;
    cout<<i+1<<" "<<p[i]+1<<"\n";
  }
}