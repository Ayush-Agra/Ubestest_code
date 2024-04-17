#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
void update(vector<pair<int,int>>& seg,int x,int ind){
  int st=(seg.size()/2)+ind;
  while(st>0){
    seg[st].first+=x;
    seg[st].second+=1;
    st=st/2;
  }
}
pair<int,int> q(vector<pair<int,int>>& seg,int st,int end,int l,int r,int root){
  if(r<st || l>end) return{0,0};
  if(l>=st && r<=end) return seg[root];
  int mid=l+(r-l)/2;
  pair<int,int> vl=q(seg,st,end,l,mid,2*root);
  pair<int,int> vl2=q(seg,st,end,mid+1,r,2*root+1);
  return {vl.first+vl2.first,vl.second+vl2.second};
}
int32_t main(){
  fastio();
  int n;cin>>n;
  vector<pair<int,int>> arr(n);
  for(int i=0;i<n;i++) cin>>arr[i].first;
  for(int i=0;i<n;i++) cin>>arr[i].second;
  sort(arr.begin(),arr.end());
  vector<pair<int,int>> vel(n);
  for(int i=0;i<n;i++){
    vel[i].first=arr[i].second;
    vel[i].second=i;
  }
  sort(vel.begin(),vel.end());
  int lg=(1<<(int)log2(n));
  lg=2*lg;
  vector<pair<int,int>> seg(2*lg,{0,0});
  int sum=0;
  for(int i=0;i<n;i++){
    update(seg,arr[vel[i].second].first,vel[i].second);
    pair<int,int> hl=q(seg,0,vel[i].second,0,lg-1,1);
    sum+=(hl.second*arr[vel[i].second].first-hl.first);
  }
  cout<<sum;
}