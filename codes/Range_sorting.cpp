#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int func(vector<int>& arr){
  stack<pair<int,int>> mx;
  mx.push({arr[0],0});
  int num=0;int ans=0;
  int grp=0;
  for(int i=1;i<arr.size();i++){
    if(mx.top().first>arr[i]){
      int cur=mx.top().first;
      int count=0;
      while(mx.size()>0 && mx.top().first>arr[i]){
        num-=mx.top().second;
        count+=mx.top().second;
        if(mx.top().second==0) count+=1;
        else grp-=1;
        mx.pop();
      }
      count+=1;grp+=1;
      num+=count;ans+=(num-grp);
      mx.push({cur,count});
    }else{
      ans+=num-grp;
      mx.push({arr[i],0});
    }
  }
  return ans;
}
int32_t main(){
  fastio();
  int tc;cin>>tc;
  while(tc--){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int ans=0;
    for(int i=0;i<n;i++){
      vector<int> vec;
      for(int j=i;j<n;j++)vec.push_back(arr[j]);
      int vl=func(vec);
      ans+=vl;
    }
    cout<<ans<<"\n";
  }
}