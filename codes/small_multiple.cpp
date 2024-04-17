#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int32_t main(){
  int k;
  cin>>k;
  vector<int> arr(k,1e7+1);
  deque<int> d;
  d.push_back(1);
  arr[1]=1;
  while(d.size()>0){
    int ele=d.front();d.pop_front();
    if(arr[(ele+1)%k]>arr[ele]+1){
      d.push_back((ele+1)%k);
      arr[(ele+1)%k]=arr[ele]+1;
    }
    if(arr[(ele*10)%k]>arr[ele]){
      d.push_front((ele*10)%k);
      arr[(ele*10)%k]=arr[ele];
    }
  }
  cout<<arr[0];
}