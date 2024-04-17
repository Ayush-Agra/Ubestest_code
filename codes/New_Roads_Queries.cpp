#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int n,m,q;
int dsu(vector<int>& conn,int a){
  if(conn[a]!=a) return conn[a]=dsu(conn,conn[a]);
  return a;
}
vector<vector<pair<int,int>>> kruskal(){
  vector<vector<pair<int,int>>> edges(n+1);
  vector<int> conn(n+1);
  vector<int> sz(n+1,1);
  for(int i=0;i<=n;i++)conn[i]=i;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    int para=dsu(conn,a);
    int parb=dsu(conn,b);
    if(para==parb)continue;
    if(sz[para]>sz[parb])swap(para,parb);
    conn[para]=parb;
    sz[parb]+=sz[para];
    edges[a].push_back({b,i+1});
    edges[b].push_back({a,i+1});
  }
  return edges;
}
void dfs(vector<vector<pair<int,int>>>& edges,vector<pair<int,int>>& bl,int root,int leaf,vector<int>& depth){
  for(int i=0;i<edges[leaf].size();i++){
    if(edges[leaf][i].first==root)continue;
    bl[edges[leaf][i].first]={leaf,edges[leaf][i].second};
    depth[edges[leaf][i].first]=depth[leaf]+1;
    dfs(edges,bl,leaf,edges[leaf][i].first,depth);
  }
}
void binary(vector<vector<pair<int,int>>>& bl){
  for(int i=1;i<bl.size();i++){
    for(int j=1;j<=n;j++){
      bl[i][j].first=bl[i-1][bl[i-1][j].first].first;
      bl[i][j].second=max(bl[i-1][bl[i-1][j].first].second,bl[i-1][j].second);
    }
  }
}
int query(int a,int b,vector<vector<pair<int,int>>>& bl,vector<int>& depth){
  if(depth[a]<depth[b]) swap(a,b);
  int climb=depth[a]-depth[b];
  int mx=0;
  for(int i=0;i<bl.size();i++){
    if(!(climb & (1<<i)))continue;
    mx=max(bl[i][a].second,mx);
    a=bl[i][a].first;
  }
  if(a==b){return mx;}
  while(a!=b){
    for(int i=0;i<bl.size();i++){
      if(bl[i][a].first==bl[i][b].first){
        if(i==0)continue;
        mx=max(bl[i-1][a].second,mx);
        mx=max(bl[i-1][b].second,mx);
        a=bl[i-1][a].first;
        b=bl[i-1][b].first;
        break;
      }
    }
  }
  return mx;
}
int32_t main(){
  fastio();
  cin>>n>>m>>q;
  vector<vector<pair<int,int>>> edges=kruskal();
  int jmp=log2(n+1)+2;
  vector<vector<pair<int,int>>> bl(jmp,vector<pair<int,int>>(n+1,{0,1e9}));
  vector<int> depth(n+1);
  depth[0]=0;
  for(int i=1;i<=n;i++){
    if(bl[0][i].first!=0) continue;
    bl[0][i]={0,1e9};
    depth[i]=1;
    dfs(edges,bl[0],0,i,depth);
  }
  binary(bl);
  for(int i=0;i<q;i++){
    int a,b;
    cin>>a>>b;
    int vl=query(a,b,bl,depth);
    if(vl==1e9)vl=-1;
    cout<<vl<<"\n";
  }
}