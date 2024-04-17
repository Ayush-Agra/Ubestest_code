#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
void update(int pos,vector<int>& st,int vl){
  int num=st.size()/2;
  num+=pos;
  while(num!=0){
    st[num]=max(st[num],vl);
    num=num/2;
  }  
}
int query(int l,int r,int st,int end,vector<int>& str,int root){
  if(l>end || r<st) return -1;
  if(l>=st && r<=end) return str[root];
  int mid=l+(r-l)/2;
  int sm=query(l,mid,st,end,str,2*root);
  sm=max(sm,query(mid+1,r,st,end,str,2*root+1));
  return sm;
}
void smupdate(int pos,vector<int>& st){
  int num=st.size()/2;
  num+=pos;
  while(num!=0){
    st[num]+=1;
    num=num/2;
  }
}
int smquery(int l,int r,int st,int end,vector<int>& str,int root){
  if(l>end || r<st) return 0;
  if(l>=st && r<=end) return str[root];
  int mid=l+(r-l)/2;
  int sm=smquery(l,mid,st,end,str,2*root);
  sm+=smquery(mid+1,r,st,end,str,2*root+1);
  return sm;
}
int32_t main(){
  fastio();
  int n,q;
  cin>>n>>q;
  vector<vector<int>> arr(n);
  for(int i=0;i<n;i++){
    int a;cin>>a;a-=1;
    arr[a].push_back(i);
  }
  int lg=log2(n)+1;
  lg=1<<lg;
  vector<int> seg(2*lg,-1);
  vector<pair<int,int>> vec;
  for(int i=0;i<n;i++){
    int l=0;
    if(arr[i].size()>0){
      l=arr[i][0];
      vec.push_back({-1,i});
    }
    for(int j=1;j<arr[i].size();j++){
      int vl=query(0,lg-1,l,arr[i][j],seg,1);
      if(vl!=-1) vec.push_back({i,vl});
      l=arr[i][j];
    }
    for(int j=0;j<arr[i].size();j++){
      update(arr[i][j],seg,i);
    }
  }
  sort(vec.begin(),vec.end());
  vector<vector<int>> qu(q);
  for(int i=0;i<q;i++){
    int a,b;cin>>a>>b;
    a-=1;b-=1;
    qu[i]={b,a,i};
  }
  sort(qu.begin(),qu.end());
  vector<int> spt(2*lg,0);
  vector<int> ans(q);
  int st=0;
  for(int i=0;i<q;i++){
    while(st<vec.size() && vec[st].first<=qu[i][0]){
      if(vec[st].first==-1)smupdate(vec[st].second,spt);
      else smupdate(vec[st].second,spt);
      st+=1;
    }
    int cnt=smquery(0,lg-1,qu[i][1],qu[i][0],spt,1);
    ans[qu[i][2]]=cnt;
  }
  for(int i=0;i<q;i++){
    cout<<ans[i]<<"\n";
  }
}