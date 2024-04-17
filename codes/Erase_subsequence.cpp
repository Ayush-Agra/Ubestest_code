#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int n;
int32_t main(){
  int tc;cin>>tc;
  while(tc--){
    string s;string t;
    cin>>s;cin>>t;
    n=s.size();
    vector<vector<int>> pos(n+2,vector<int>(26,n));
    for(int i=n-1;i>=0;i--){
      pos[i][s[i]-'a']=i;
      if(i==n-1)continue;
      for(int j=0;j<26;j++){
        pos[i][j]=min(pos[i][j],pos[i+1][j]);
      }
    }
    if(t.size()==1){
      if(pos[0][t[0]-'a']!=n)cout<<"YES\n";
      else cout<<"NO\n";
      continue;
    }
    int flg=0;
    for(int i=1;i<t.size();i++){
      string a=t.substr(0,i);
      string b=t.substr(i);
      vector<vector<int>> dp(a.size()+1,vector<int>(b.size()+1,n));
      dp[0][0]=-1;
      for(int j=0;j<=a.size();j++){
        if(j==0){
          for(int k=1;k<=b.size();k++){
            dp[0][k]=pos[dp[0][k-1]+1][b[k-1]-'a'];
          }
          continue;
        }
        for(int k=0;k<=b.size();k++){
          if(k==0)dp[j][0]=pos[dp[j-1][0]+1][a[j-1]-'a'];
          else{
            dp[j][k]=min(pos[dp[j-1][k]+1][a[j-1]-'a'],pos[dp[j][k-1]+1][b[k-1]-'a']);
          }
        }
      }
      if(dp[a.size()][b.size()]!=n){flg=1;break;}
    }
    if(flg){
      cout<<"YES\n";
    }else{
      cout<<"NO\n";
    }
  }
}