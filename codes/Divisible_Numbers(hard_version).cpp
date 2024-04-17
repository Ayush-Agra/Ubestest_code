#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
vector<int> div(int a){
  int vl=sqrt(a)+1;
  vector<int> arr;
  for(int i=1;i<vl;i++){
    if(a%i==0){
      arr.push_back(i);
      if(i!=a/i)arr.push_back(a/i);
    }
  }
  return arr;
}

int32_t main(){
  fastio();
  int tc;cin>>tc;
  while(tc--){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<int> fir=div(a);
    vector<int> sec=div(b);
    vector<int> hl;
    for(int i=0;i<fir.size();i++){
      for(int j=0;j<sec.size();j++){
        hl.push_back(fir[i]*sec[j]);
      }
    }
    int vl=a*b;
    int flg=0;
    pair<int,int> ans;
    for(int i=0;i<hl.size();i++){
      if(hl[i]>c)continue;
      int gd=vl/hl[i];
      int y=d/gd;y=y*gd;
      if(y<=b)continue;
      int gdx=hl[i];
      int x=c/gdx;x=gdx*x;
      if(x<=a)continue;
      ans.first=x;ans.second=y;
      flg=1;break;
    }
    if(flg==0){ans.first=-1;ans.second=-1;}
    cout<<ans.first<<" "<<ans.second<<"\n";
  }
}