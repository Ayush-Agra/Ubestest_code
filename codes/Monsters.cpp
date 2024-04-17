#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
void dfs(vector<vector<int>>& edges,set<pair<int,int>>& uset,vector<int>& arr,vector<int>& vis,int leaf,int& cnt){
  // cout<<leaf<<"\n";
  vis[leaf]=2;cnt+=1;
  for(int i=0;i<edges[leaf].size();i++){
    if(uset.find({arr[edges[leaf][i]],edges[leaf][i]})!=uset.end() || vis[edges[leaf][i]]==2)continue;
    uset.insert({arr[edges[leaf][i]],edges[leaf][i]});
  }
  if(uset.size()==0){vis[leaf]=1;return;}
  pair<int,int> ele=*uset.begin();
  uset.erase(ele);
  if(ele.first>cnt){vis[leaf]=1;return;}
  dfs(edges,uset,arr,vis,ele.second,cnt);
  vis[leaf]=1;
}
int32_t main(){
  int tc;cin>>tc;
  while(tc--){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<vector<int>> edges(n);
    for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      a-=1;b-=1;
      edges[a].push_back(b);
      edges[b].push_back(a);
    }
    vector<int> vis(n,0);
    int flg=0;
    for(int i=0;i<n;i++){
      if(arr[i]!=0 || vis[i])continue;
      set<pair<int,int>> uset;
      int cnt=0;
      dfs(edges,uset,arr,vis,i,cnt);
      // cout<<"sdf"<<endl;
      if(cnt==n){flg=1;break;}
    }
    if(flg) cout<<"YES\n";
    else cout<<"NO\n";
  }
}