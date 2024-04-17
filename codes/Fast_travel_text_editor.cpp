#include <bits/stdc++.h>
using namespace std;
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int n;
void dfs(vector<vector<pair<int,int>>>& edges,vector<int>& arr,int root){
  deque<pair<int,int>> d;
  arr[root]=0;
  d.push_back({0,root});
  while(d.size()>0){
    pair<int,int> ele=d.front();
    d.pop_front();
    for(int i=0;i<edges[ele.second].size();i++){
      if(arr[edges[ele.second][i].first]>ele.first+edges[ele.second][i].second){
        arr[edges[ele.second][i].first]=ele.first+edges[ele.second][i].second;
        if(edges[ele.second][i].second==0){
          d.push_front({arr[edges[ele.second][i].first],edges[ele.second][i].first});
        }else d.push_back({arr[edges[ele.second][i].first],edges[ele.second][i].first});
      }
    }
  }
}
int32_t main(){
  fastio();
  string s;
  cin>>s;
  n=s.size();
  int a=26*26;
  vector<vector<pair<int,int>>> edges(n-1+a);
  vector<vector<int>> cnt(26,vector<int>(26));
  int sm=1;
  for(int i=0;i<26;i++){
    for(int j=0;j<26;j++){
      cnt[i][j]=sm;
      sm+=1;
    }
  }
  for(int i=0;i<(n-1);i++){
    int vl=n-2+cnt[s[i]-'a'][s[i+1]-'a'];
    edges[i].push_back({vl,1});
    edges[vl].push_back({i,0});
    if(i==0){
      edges[i].push_back({i+1,1});
    }else if(i==n-2){
      edges[i].push_back({i-1,1});
    }else{
      edges[i].push_back({i+1,1});
      edges[i].push_back({i-1,1});
    }
  }
  vector<vector<int>> dm(a,vector<int>(n+a-1,1e9));
  vector<vector<int>> ind(a,vector<int>(n+a-1,1e9));
  for(int i=0;i<a;i++){
    dfs(edges,dm[i],n+i-1);
    for(int j=0;j<n;j++){
      ind[i][j]=dm[i][j]+1;
    }
  }
  int q;cin>>q;
  for(int i=0;i<q;i++){
    int s,e;cin>>s>>e;
    s-=1;e-=1;
    int tem=min(s,e);e=max(s,e);
    int mn=e-tem;
    for(int j=0;j<a;j++){
      mn=min(dm[j][e]+ind[j][tem],mn);
    }
    cout<<mn<<"\n";
  }
}