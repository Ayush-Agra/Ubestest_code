#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
 
int32_t main(){
  int tc;cin>>tc;
  while(tc--){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int cnt=0;
    int ans=0;
    for(int i=0;i<n;i++){
      ans+=(cnt*min(m,k)+arr[i]*min(m,k));
      cnt+=min(m,k);
      k-=min(m,k);
    }
    cout<<ans<<"\n";
  }
}