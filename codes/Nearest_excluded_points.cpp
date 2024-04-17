#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int32_t main(){
  int n;cin>>n;
  vector<vector<int>> mrk(n,vector<int>(3,0));
  map<pair<int,int>,int> umap;
  set<vector<int>> uset;
  int cnt=0;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    umap.insert({{a,b},i});
  }
  for(auto x:umap){
    pair<int,int> ele=x.first;
    vector<int> cur(2);
    cur[0]=-1;cur[1]=1;
    for(int i=0;i<2;i++){
      int a=cur[i]+ele.first;int b=ele.second;
      if(umap.find({a,b})==umap.end()){
        cnt+=1;
        mrk[x.second][0]=1;
        mrk[x.second][1]=a;
        mrk[x.second][2]=b;
        uset.insert({1,ele.first,ele.second});
        break;
      }
      a=ele.first,b+=cur[i];
      if(umap.find({a,b})==umap.end()){
        cnt+=1;
        mrk[x.second][0]=1;
        mrk[x.second][1]=a;
        mrk[x.second][2]=b;
        uset.insert({1,ele.first,ele.second});
        break;
      }
    }
  }
  while(cnt<n){
    vector<int> x=*uset.begin();
    uset.erase(x);
    vector<int> cur(2);
    cur[0]=-1;cur[1]=1;
    for(int i=0;i<2;i++){
      int a=cur[i]+x[1];int b=x[2];
      if(umap.find({a,b})!=umap.end() && mrk[umap[{a,b}]][0]==0){
        int ind=umap[{a,b}];int indto=umap[{x[1],x[2]}];
        mrk[ind][0]=1;
        mrk[ind][1]=mrk[indto][1];
        mrk[ind][2]=mrk[indto][2];
        uset.insert({1+x[0],a,b});
        cnt+=1;
      }
      a=x[1];b+=cur[i];
      if(umap.find({a,b})!=umap.end() && mrk[umap[{a,b}]][0]==0){
        int ind=umap[{a,b}];int indto=umap[{x[1],x[2]}];
        mrk[ind][0]=1;
        mrk[ind][1]=mrk[indto][1];
        mrk[ind][2]=mrk[indto][2];
        uset.insert({1+x[0],a,b});
        cnt+=1;
      }
    }
  }
  for(int i=0;i<n;i++){
    cout<<mrk[i][1]<<" "<<mrk[i][2]<<"\n";
  }
}