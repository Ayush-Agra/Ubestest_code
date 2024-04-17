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
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<vector<pair<int,int>>> ch(n);
    for(int i=0;i<n;i++){
      if(arr[i]==0){
        ch[i].push_back({i,1});
        continue;
      }
      vector<int> pre(n+1,0);
      pre[arr[i]]=1;
      int mn=0;int ind=-1;
      for(int j=i-1;j>=0;j--){
        if(arr[j]>=arr[i] || pre[arr[j]]){
          pre[arr[j]]=1;
          continue;
        }
        pre[arr[j]]=1;
        if(mn!=arr[j]) continue;
        for(int k=mn+1;k<=n;k++){
          if(!pre[k]){mn=k;break;}
        }
        if(mn>arr[i]){ind=j;break;}
      }
      if(ind!=-1)ch[i].push_back({ind,mn});
    }
    for(int i=n-1;i>=0;i--){
      vector<int> pre(n+1,0);
      int mn=0;int ind=-1;
      pre[arr[i]]=1;
      for(int j=i+1;j<n;j++){
        if(arr[j]>arr[i] || pre[arr[j]]==1){
          pre[arr[j]]=1;
          continue;
        }
        pre[arr[j]]=1;
        if(mn!=arr[j]) continue;
        for(int k=mn+1;k<=n;k++){
          if(!pre[k]){mn=k;break;}
        }
        if(mn>arr[i]){ind=j;break;}
      }
      if(ind!=-1)ch[ind].push_back({i,mn});
    }
    vector<vector<int>> dp(n,vector<int>(n+1,0));
    int mx=0;
    dp[0][0]=1;
    if(ch[0].size()>0){dp[0][1]=1;mx=1;}
    for(int i=1;i<n;i++){
      for(int j=0;j<=n;j++){
        dp[i][j]=dp[i-1][j];
      }
      for(int j=0;j<ch[i].size();j++){
        int l=ch[i][j].first-1;
        int vl=ch[i][j].second;
        if(l<0){
          dp[i][vl]=1;
          mx=max(mx,vl);
          continue;
        }
        for(int k=0;k<=n;k++){
          if(!dp[l][k])continue;
          dp[i][(k^vl)]=1;
          mx=max((k^vl),mx);
        }
      }
    }
    cout<<mx<<"\n";
  }
}