#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
///soln__2//(using dijkstra)
int32_t main(){
  fastio();
  int tc;cin>>tc;
  while(tc--){
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<vector<int>> nxt(n,vector<int>(n+1,1e9));
    for(int i=0;i<n;i++){
      vector<int> cur(n+1,0);
      int mx=0;
      for(int j=i;j<n;j++){
        if(arr[j]!=mx){cur[arr[j]]=1;continue;}
        cur[mx]=1;
        while(cur[mx])mx+=1;
        nxt[i][mx]=j;
      }
    }
    for(int i=n-2;i>=0;i--){
      for(int j=0;j<=n;j++){
        nxt[i][j]=min(nxt[i+1][j],nxt[i][j]);
      }
    }
    vector<int> dist(n+1,1e9);
    dist[0]=-1;
    vector<int> done(n+1,0);
    int mx=0;
    for(int i=0;i<=n;i++){
      int ind=-1;int mn=1e9;
      for(int j=0;j<=n;j++){
        if(!done[j]){
          if(mn>dist[j]){
            mn=dist[j];
            ind=j;
          }
        }
      }
      if(ind==-1)break;
      done[ind]=1;
      mx=max(ind,mx);
      int vl=mn+1;
      if(vl>=n)continue;
      for(int j=0;j<=n;j++){
        if(nxt[vl][j]==1e9)continue;
        dist[(ind^j)]=min(dist[(ind^j)],nxt[vl][j]);
      }
    }
    cout<<mx<<"\n";
  }
}