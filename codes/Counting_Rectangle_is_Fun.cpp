#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int s[42][42]={0};int pre[42][42]={0};
int dp[42][42][42][42]={0};
void func(int n,int m){
  for(int i=n;i>=0;i--){
    for(int j=m;j>=0;j--){
      dp[n][m][i][j]+=dp[n][m][i+1][j];
    }
  }
  for(int i=n;i>=0;i--){
    for(int j=m;j>=0;j--){
      dp[n][m][i][j]+=dp[n][m][i][j+1];
    }
  }
}
bool check(int a,int b,int c,int d){
  int vl=pre[a][b]+pre[c+1][d+1]-pre[c+1][b]-pre[a][d+1];
  if(vl==0)return true;
  else return false;
}
int32_t main(){
  fastio();
  int n,m,q;
  cin>>n>>m>>q;
  for(int i=0;i<n;i++){
    string a;cin>>a;
    for(int j=0;j<m;j++){
      s[i][j]=a[j]-'0';
    }
  }
  for(int i=n-1;i>=0;i--){
    for(int j=m-1;j>=0;j--){
      pre[i][j]=s[i][j]+pre[i+1][j];
    }
  }
  for(int i=n-1;i>=0;i--){
    for(int j=m-1;j>=0;j--){
      pre[i][j]+=pre[i][j+1];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      for(int k=0;k<=i;k++){
        for(int l=0;l<=j;l++){
          if(check(k,l,i,j))dp[i][j][k][l]=1;
          else dp[i][j][k][l]=0;
        }
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      func(i,j);
    }
  }
  for(int i=n-1;i>=0;i--){
    for(int j=m-1;j>=0;j--){
      for(int k=0;k<n;k++){
        for(int l=0;l<m;l++){
          dp[i][j][k][l]+=(dp[i+1][j][k][l]+dp[i][j+1][k][l]-dp[i+1][j+1][k][l]);
        }
      }
    }
  }
  for(int i=0;i<q;i++){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    a-=1;b-=1;c-=1;d-=1;
    int vl=dp[a][b][a][b]+dp[a][b][c+1][d+1]-dp[a][b][c+1][b]-dp[a][b][a][d+1];
    vl-=(dp[a][d+1][a][b]+dp[a][d+1][c+1][d+1]-dp[a][d+1][c+1][b]-dp[a][d+1][a][d+1]);
    vl-=(dp[c+1][b][a][b]+dp[c+1][b][c+1][d+1]-dp[c+1][b][c+1][b]-dp[c+1][b][a][d+1]);
    vl+=(dp[c+1][d+1][a][b]+dp[c+1][d+1][c+1][d+1]-dp[c+1][d+1][c+1][b]-dp[c+1][d+1][a][d+1]);
    cout<<vl<<"\n";
  }
}