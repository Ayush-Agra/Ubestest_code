#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int32_t main(){
  fastio();
  int tc;
  cin>>tc;
  while(tc--){
    int n,k;
    cin>>n>>k;
    vector<int> cnt(n+1,0);
    vector<int> arr2(n);
    for(int i=0;i<n;i++){
      int a;cin>>a;
      cnt[a]+=1;
      arr2[i]=a;
    }
    vector<int> arr;
    for(int i=1;i<n+1;i++){
      for(int j=0;j<cnt[i];j++) arr.push_back(i);
    }
    int r=((n-k)/2)+k+((n-k)%2);
    int mn=1e9;
    int x=0;
    int y=-1;
    for(int i=0;i<n-r+1;i++){
      int st=arr[i];
      int end=arr[i+r-1];
      if(end-st<mn){
        mn=end-st;
        x=st;
        y=end;
      }
    }
    cout<<x<<" "<<y<<"\n";
    vector<pair<int,int>> pr;
    int l=0;
    int be=0;
    for(int i=0;i<n;i++){
      if(arr2[i]>=x && arr2[i]<=y) be+=1;
      else be-=1;
      if(be>0){
        pr.push_back({l+1,i+1});
        be=0;l=i+1;
      }
    }
    for(int i=0;i<k-1;i++){
      cout<<pr[i].first<<" "<<pr[i].second<<"\n";
    }
    cout<<pr[k-1].first<<" "<<n<<"\n";
  }
}