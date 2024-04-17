#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int od(vector<int>& arr){
  int mx=0;int mn=1e9;
  for(int i=0;i<arr.size()-1;i++){
    mx=max(mx,max(arr[i],arr[i+1]));
    mn=min(mn,arr[i]);
  }
  mn=min(mn,arr[arr.size()-1]);
  return min(mx,2*mn);
}
int func(vector<int> arr,int k){
  set<pair<int,int>> uset;
  int n=arr.size();
  for(int i=0;i<n;i++){
    uset.insert({arr[i],i});
  }
  int wild=0;
  for(int i=0;i<k;i++){
    pair<int,int> ele=*uset.begin();
    uset.erase(ele);
    if(i==k-1)wild=od(arr);
    arr[ele.second]=1e9;
  }
  //cout<<wild<<"\n";
  int d=2*(*uset.begin()).first;
  int mx=0;
  for(int i=0;i<n-1;i++){
    mx=max(mx,min(arr[i],arr[i+1]));
  }
  return max(min(d,mx),wild);
}
int32_t main(){
  fastio();
  int tc;cin>>tc;
  int sm=0;
  while(tc--){
    sm+=1;
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    if(k==n){
      int vl=1e9;
      cout<<vl<<"\n";
      continue;
    }
    cout<<func(arr,k)<<"\n";
  }
}