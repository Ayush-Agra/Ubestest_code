#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int32_t main(){
  int n;cin>>n;
  vector<vector<int>> arr(n);
  for(int i=0;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    arr[i]={a,b,c,i+1};
  }
  sort(arr.begin(),arr.end());
  int bg=1e9;
  vector<pair<int,int>> ans;
  for(int i=0;i<3;i++){
    arr.push_back({bg,bg,bg,bg});
    vector<vector<int>> cur;
    int hl=2-i;n=arr.size();
    for(int j=1;j<n;j+=2){
      int flg=1;
      for(int k=0;k<hl;k++){
        if(arr[j][k]!=arr[j-1][k])flg=0;
      }
      if(flg){
        ans.push_back({arr[j][3],arr[j-1][3]});
      }else{
        cur.push_back(arr[j-1]);
        j-=1;
      }
    }
    arr=cur;
  }
  for(int i=0;i<ans.size();i++){
    cout<<ans[i].first<<" "<<ans[i].second<<"\n";
  }
}