#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int bs(vector<pair<int,int>>& arr,int num){
  int l=0;
  int r=arr.size()-1;
  while(l<=r){
    int mid=l+(r-l)/2;
    if(arr[mid].first>num) r=mid-1;
    else l=mid+1;
  }
  return l-1;
}
int mod=1e9+7;
int32_t main(){
  fastio();
  int tc;cin>>tc;
  while(tc--){
    int n;cin>>n;
    int k;cin>>k;
    vector<int> arr(n);
    vector<pair<int,int>> sto(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<n;i++){
      sto[i].first=min(arr[i]+i+1,arr[i]+(n-i));
      sto[i].second=i;
    }
    sort(sto.begin(),sto.end());
    for(int i=1;i<n;i++)sto[i].first+=sto[i-1].first;
    int ans=0;
    for(int i=0;i<n;i++){
      int vl=arr[sto[i].second]+sto[i].second+1;
      int num=k-vl;
      if(num<0) continue;
      int pos=bs(sto,num);
      if(pos<i) ans=max(ans,2+pos);
      else{
        num=k-vl+min(vl,arr[sto[i].second]+(n-sto[i].second));
        pos=bs(sto,num);
        ans=max(ans,pos+1);
      }
    }
    cout<<ans<<"\n";
  }
}