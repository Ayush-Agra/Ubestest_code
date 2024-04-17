#include <bits/stdc++.h>
using namespace std;
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
vector<int> uset(1000001,0);
int num=0;
void dfs(vector<vector<int>>&edges,int leaf,vector<int>&arr,vector<int>&hl){
  if(arr[leaf]!=-1){
    if(uset[arr[leaf]]==0) num+=1;
    uset[arr[leaf]]+=1;
    hl[leaf]=num;
  }
  for(int i=0;i<edges[leaf].size();i++){
    dfs(edges,edges[leaf][i],arr,hl);
  }
  if(arr[leaf]!=-1){
    if(uset[arr[leaf]]==1) num-=1;
    uset[arr[leaf]]-=1;
  }
}
int32_t main(){
  fastio();
  int q;cin>>q;
  int vl=log2(q);
  vl+=1;
  vector<vector<int>> spt(vl,vector<int>(q+1,0));
  vector<int> arr(q+1,-1);
  int cnt=0;
  int par=0;
  stack<int> stk;
  vector<int> ans;
  for(int i=0;i<q;i++){
    char c;cin>>c;
    if(c=='+'){
      int a;cin>>a;
      stk.push(par);
      cnt+=1;
      arr[cnt]=a;
      spt[0][cnt]=par;
      par=cnt;
      for(int i=1;i<vl;i++){
        spt[i][cnt]=spt[i-1][spt[i-1][cnt]];
      }
    }else if(c=='-'){
      int a;cin>>a;
      stk.push(par);
      while(a>0){
        int nm=log2(a);
        par=spt[nm][par];
        a-=(1<<nm);
      }
    }else if(c=='!'){
      par=stk.top();
      stk.pop();
    }else{
      ans.push_back(par);
    }
  }
  vector<vector<int>> edges(cnt+1);
  for(int i=1;i<=cnt;i++){
    edges[spt[0][i]].push_back(i);
  }
  vector<int> hl(cnt+1);
  dfs(edges,0,arr,hl);
  for(int i=0;i<ans.size();i++){
    cout<<hl[ans[i]]<<"\n";
  }
}