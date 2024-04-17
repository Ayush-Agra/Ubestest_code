#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
pair<vector<int>,double> func(vector<vector<int>>& mes,int k){
  vector<pair<double,int>> hl;
  for(int i=0;i<mes.size();i++){
    double cnt=0;
    for(int j=0;j<mes[i].size();j++){
      if(mes[i][j]>=k)cnt+=1.0;
      else{
        cnt+=((double)mes[i][j]/(double)k);
      }
    }
    if(cnt==0)continue;
    hl.push_back({cnt,i});
  }
  sort(hl.begin(),hl.end());
  double cnt=0;
  vector<int> ans;
  int m=hl.size()-k;
  if(m<0)m=0;
  for(int i=hl.size()-1;i>=m;i--){
    ans.push_back(hl[i].second);
    cnt+=hl[i].first;
  }
  return {ans,cnt};
}
int32_t main(){
  int n;cin>>n;
  vector<vector<int>> arr(2e5+1);
  for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;
    arr[a].push_back(b);
  }
  double mx=0;
  vector<int> res;
  int upto=min(n+1,(int)21);
  for(int i=1;i<upto;i++){
    pair<vector<int>,double> vec=func(arr,i);
    if(vec.second>mx){
      mx=vec.second;res=vec.first;
    }
  }
  cout<<res.size()<<"\n";
  for(int i=0;i<res.size();i++){
    cout<<res[i]<<" ";
  }
  cout<<"\n";
}