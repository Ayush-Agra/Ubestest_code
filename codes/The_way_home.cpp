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
    int n,m,p;
    cin>>n>>m>>p;
    vector<int> w(n);
    for(int i=0;i<n;i++)cin>>w[i];
    vector<vector<pair<int,int>>> edges(n);
    for(int i=0;i<m;i++){
      int a,b,c;
      cin>>a>>b>>c;
      a-=1;b-=1;
      edges[a].push_back({b,c});
    }
    set<vector<int>> uset;
    vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(n,{1e14,0}));
    dp[0][0]={0,p};
    uset.insert({0,-p,0,0});
    while(uset.size()!=0){
      vector<int> det=*uset.begin();
      uset.erase(det);
      int per=det[0];int coin=-det[1];
      int u=det[2];int best=det[3];
      // cout<<"sdf"<<u<<" "<<best<<" "<<per<<" "<<coin<<endl;
      for(int i=0;i<edges[u].size();i++){
        int v=edges[u][i].first;
        int cst=edges[u][i].second;
        int cbest=best;
        int cper=per;int ccoin=coin;
        if(ccoin>=cst)ccoin-=cst;
        else{
          int calc=cst-ccoin;
          if(calc%w[cbest]!=0)calc+=w[cbest];
          calc=(calc/w[cbest]);
          cper+=calc;ccoin=ccoin+calc*w[cbest]-cst;
        }
        if(w[v]>w[cbest])cbest=v;
        // cout<<v<<" "<<cbest<<" "<<ccoin<<" "<<cper<<endl;
        if(dp[v][cbest].first>cper || (dp[v][cbest].first==cper && dp[v][cbest].second<ccoin)){
          uset.erase({dp[v][cbest].first,-dp[v][cbest].second,v,cbest});
          dp[v][cbest]={cper,ccoin};
          uset.insert({dp[v][cbest].first,-dp[v][cbest].second,v,cbest});
        }
      }
    }
    // for(int i=0;i<n;i++){
    //   for(int j=0;j<n;j++){
    //     cout<<dp[i][j].first<<" ";
    //   }
    //   cout<<endl;
    // }
    int mn=1e14;
    for(int i=0;i<n;i++){
      mn=min(mn,dp[n-1][i].first);
    }
    if(mn==1e14)mn=-1;
    cout<<mn<<"\n";
  }
}