#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
class segtree{
  public:
  vector<pair<int,int>> pre;
  int vl=0;
  segtree(int n){
    vl=log2(n);
    if((1<<vl)<n)vl+=1;
    vector<pair<int,int>> hl((1<<(vl+1)),{0,0});
    pre=hl;
  }
  void build(vector<int>& a){
    int st=1<<vl;
    for(int i=st;i<st+a.size();i++)pre[i]={a[i-st],a[i-st]};
    for(int i=st-1;i>0;i--){
      pre[i].second=pre[2*i].second+pre[2*i+1].second;
      pre[i].first=max(pre[2*i].first+pre[2*i+1].second,pre[2*i+1].first);
    }
  }
  void update(int pos,int a){
    int st=(1<<vl)+pos;
    pre[st]={a,a};
    while(st!=0){
      st=st/2;
      pre[st].second=pre[2*st].second+pre[2*st+1].second;
      pre[st].first=max(pre[2*st].first+pre[2*st+1].second,pre[2*st+1].first);
    }
  }
};
int32_t main(){
  fastio();
  int n,q;
  cin>>n>>q;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n-1);
  int sum=0;
  for(int i=0;i<n;i++){cin>>a[i];sum+=a[i];}
  for(int i=0;i<n;i++)cin>>b[i];
  for(int i=0;i<n-1;i++)cin>>c[i];
  vector<int> d(n);
  for(int i=0;i<n;i++)d[i]=a[i]-b[i];
  segtree seg(d.size());
  seg.build(d);
  for(int i=0;i<q;i++){
    int p,x,y,z;
    cin>>p>>x>>y>>z;
    p-=1;sum-=a[p];
    a[p]=x;sum+=x;
    seg.update(p,x-y);
    cout<<sum-max((int)0,seg.pre[1].first)<<"\n";
  }
}