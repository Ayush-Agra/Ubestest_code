#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int32_t main(){
  freopen("lasers.in", "r", stdin);
  freopen("lasers.out", "w", stdout);
  int n,xi,yi,xf,yf;
  cin>>n>>xi>>yi>>xf>>yf;
  map<int,vector<pair<int,int>>> hor;
  map<int,vector<pair<int,int>>> vert;
  vector<pair<int,int>> edges(n);
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    edges[i]={a,b};
    if(hor.find(a)==hor.end()){
      hor[a]={{b,i}};
    }else{
      hor[a].push_back({b,i});
    }
    if(vert.find(b)==vert.end()){
      vert[b]={{a,i}};
    }else{
      vert[b].push_back({a,i});
    }
  }
  if(hor.find(xf)==hor.end()){
    hor[xf]={{yf,n}};
  }else{
    hor[xf].push_back({yf,n});
  }
  if(vert.find(yf)==vert.end()){
    vert[yf]={{xf,n}};
  }else{
    vert[yf].push_back({xf,n});
  }
  vector<vector<int>> ln(n+1,vector<int>(2,1e9));
  queue<vector<int>> stk;
  stk.push({xi,0,-1,0});
  stk.push({yi,1,-1,0});
  while(stk.size()>0){
    int u=stk.front()[0];
    int dir=stk.front()[1];
    int pos=stk.front()[2];
    int dist=stk.front()[3];
    stk.pop();
    if(dir==0 && hor.find(u)!=hor.end()){
      vector<pair<int,int>> vl=hor[u];
      for(int i=0;i<vl.size();i++){
        if(vl[i].second==pos) continue;
        if(ln[vl[i].second][0]>dist+1){
          ln[vl[i].second][0]=dist+1;
          if(vl[i].second==n) break;
          stk.push({edges[vl[i].second].second,1,vl[i].second,dist+1});
        }
      }
    }else if(dir==1 && vert.find(u)!=vert.end()){
      vector<pair<int,int>> vl=vert[u];
      for(int i=0;i<vl.size();i++){
        if(vl[i].second==pos) continue;
        if(ln[vl[i].second][1]>dist+1){
          ln[vl[i].second][1]=dist+1;
          if(vl[i].second==n) break;
          stk.push({edges[vl[i].second].first,0,vl[i].second,dist+1});
        }
      }
    }
    int num=min(ln[n][0],ln[n][1]);
    if(num!=1e9) break;
  }
  int num=min(ln[n][0],ln[n][1]);
  if(num!=1e9){
    cout<<num-1;
  }else{
    cout<<-1;
  }
}