#include <bits/stdc++.h>
using namespace std;
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
    vector<int> arr(n);
    for(int i=0;i<n;i++){
      char c;cin>>c;
      arr[i]=c-'0';
    }
    vector<vector<int>> pre(n,vector<int>(k+2,0));
    vector<vector<int>> suf(n,vector<int>(k+2,0));
    if(arr[0]==0) pre[0][0]=1;
    else pre[0][1]=1;
    if(arr[n-1]==0) suf[n-1][0]=1;
    else suf[n-1][1]=1;
    for(int i=1;i<n;i++){
      for(int j=0;j<=k;j++){
        if(arr[i]==0){
          pre[i][j]=pre[i-1][j]+1;
        }else if(j!=0){
          pre[i][j]=pre[i-1][j-1]+1;
        }
        if(arr[n-1-i]==0){
          suf[n-1-i][j]=suf[n-i][j]+1;
        }else if(j!=0){
          suf[n-1-i][j]=suf[n-i][j-1]+1;
        }
      }
    }
    for(int i=1;i<n;i++){
      for(int j=0;j<=k;j++){
        pre[i][j]=max(pre[i-1][j],pre[i][j]);
        if(j!=0)pre[i][j]=max(pre[i][j-1],pre[i][j]);
        suf[n-1-i][j]=max(suf[n-i][j],suf[n-1-i][j]);
        if(j!=0)suf[n-1-i][j]=max(suf[n-i-1][j-1],suf[n-1-i][j]);
      }
    }
    vector<int> sm(n,0);
    if(arr[0]==1) sm[0]=1;
    for(int i=1;i<n;i++) sm[i]=sm[i-1]+arr[i];
    vector<int> dp(n+1,-1);
    for(int i=0;i<n;i++){
      for(int j=i;j<n;j++){
        int ln=j-i+1;
        int cnt=sm[j]-sm[i]+arr[i];
        int sub=k-(ln-cnt);
        if(sub>=0){
          if(i==0 && j!=(n-1)) dp[ln]=max(dp[ln],suf[j+1][sub]);
          else if(i==0 && j==n-1) dp[ln]=0;
          else if(j==n-1 && i!=0) dp[ln]=max(dp[ln],pre[i-1][sub]);
          else{
            dp[ln]=max(dp[ln],pre[i-1][sub]);
            dp[ln]=max(dp[ln],suf[j+1][sub]);
          }
        }
      }
    }
    for(int j=1;j<=n;j++){
      int mx=pre[n-1][k]*j;
      for(int i=1;i<=n;i++){
        int vl=0;
        if(dp[i]!=-1) vl=dp[i]*j+i;
        mx=max(vl,mx);
      }
      cout<<mx<<" ";
    }
    cout<<"\n";
  }
}