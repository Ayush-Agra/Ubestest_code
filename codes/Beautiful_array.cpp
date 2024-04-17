#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int32_t main(){
  fastio();
  int n,x;
  cin>>n>>x;
  vector<int> arr(n);
  for(int i=0;i<n;i++)cin>>arr[i];
  int zero=0;
  vector<vector<int>> prev(3,vector<int>(2,0));
  for(int i=0;i<n;i++){
    vector<vector<int>> nxt(3,vector<int>(2,0));
    nxt[0][0]=max(prev[0][0]+arr[i],zero);
    nxt[0][1]=nxt[0][0];
    nxt[1][0]=max(nxt[0][1],prev[1][0]+x*arr[i]);
    nxt[1][1]=nxt[1][0];
    nxt[2][0]=max(prev[2][0]+arr[i],nxt[1][1]);
    nxt[2][1]=max(prev[2][1],nxt[2][0]);
    prev=nxt;
  }
  cout<<prev[2][1]<<"\n";
}