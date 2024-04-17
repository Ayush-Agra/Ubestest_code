#include <bits/stdc++.h>
using namespace std;
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
void fld(vector<vector<int>>& edges){
  int v=edges.size();
  for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
      for(int k=0;k<v;k++){
        edges[j][k]=min(edges[j][k],edges[j][i]+edges[i][k]);
      }
    }
  }
}
int32_t main(){
  fastio();
  int n,m,r;
  cin>>n>>m>>r;
  vector<vector<vector<int>>> path(m,vector<vector<int>>(n,vector<int>(n,0)));
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        cin>>path[i][j][k];
      }
    }
  }
  vector<vector<vector<int>>> all(n+1,vector<vector<int>>(n,vector<int>(n,1e9)));
  for(int i=0;i<m;i++){
    fld(path[i]);
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        all[0][j][k]=min(path[i][j][k],all[0][j][k]);
      }
    }
  }
  for(int i=1;i<=n;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        for(int l=0;l<n;l++){
          all[i][j][l]=min(all[i-1][j][k]+all[0][k][l],all[i][j][l]);
        }
      }
    }
  }
  for(int i=0;i<r;i++){
    int a,b,k;
    cin>>a>>b>>k;a-=1;b-=1;
    int vl=min(k,n);
    cout<<all[vl][a][b]<<"\n";
  }
}