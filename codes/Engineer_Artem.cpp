#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int32_t main(){
  fastio();
  int tc;cin>>tc;
  while(tc--){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cin>>arr[i][j];
        if(i%2==0){
          if(j%2==0 && arr[i][j]%2!=0)arr[i][j]+=1;
          else if(j%2==1 && arr[i][j]%2==0)arr[i][j]+=1;
        }else{
          if(j%2==0 && arr[i][j]%2==0)arr[i][j]+=1;
          else if(j%2==1 && arr[i][j]%2!=0)arr[i][j]+=1;
        }
      }
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        cout<<arr[i][j]<<" ";
      }
      cout<<"\n";
    }
  }
}