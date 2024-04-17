#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int32_t main(){
  int n;cin>>n;
  vector<int> arr(1000001,-1);
  for(int i=0;i<n;i++){
    int a;cin>>a;
    int b;cin>>b;
    arr[a]=b;
  }
  set<int> umap;
  int ans=0;
  for(int i=0;i<1000001;i++){
    if(arr[i]==-1) continue;
    if(umap.lower_bound(-arr[i])==umap.end()){
      ans+=1;
      umap.insert(-arr[i]);
      continue;
    }
    umap.erase(umap.lower_bound(-arr[i]));
    umap.insert(-arr[i]);
  }
  cout<<ans<<"\n";
}