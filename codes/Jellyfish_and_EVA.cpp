#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
vector<vector<double>> pro;
void func(){
  pro.push_back({0});
  pro.push_back({0,1});
  pro.push_back({0,0.5,0});
  for(double i=3;i<=5000;i++){
    vector<double> arr(i+1);
    arr[0]=0;arr[1]=1/i;
    for(double j=2;j<=i;j++){
      arr[j]=pro[i-2][j-2]*((j-2)/i);
      arr[j]+=pro[i-2][j-1]*((i-j)/i);
    }
    pro.push_back(arr);
  }
}
double calc(vector<double>& arr){
  sort(arr.begin(),arr.end());
  double sm=0;int n=arr.size();
  for(int i=n-1;i>=0;i--){
    sm+=pro[n][n-i]*arr[i];
  }
  return sm;
}
double dfs(vector<vector<int>>& edges,int leaf,vector<double>& f){
  if(f[leaf]!=-1)return f[leaf];
  vector<double> arr;
  for(int i=0;i<edges[leaf].size();i++){
    arr.push_back(dfs(edges,edges[leaf][i],f));
  }
  if(arr.size()==0)return f[leaf]=0;
  return f[leaf]=calc(arr);
}
int32_t main(){
  fastio();
  cout<<setprecision(14);
  int tc;cin>>tc;
  func();
  while(tc--){
    int n;cin>>n;
    int m;cin>>m;
    vector<vector<int>> edges(n);
    for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      a-=1;b-=1;
      edges[a].push_back(b);
    }
    vector<double> f(n,-1);
    f[n-1]=1;
    f[0]=dfs(edges,0,f);
    cout<<f[0]<<"\n";
  }
}