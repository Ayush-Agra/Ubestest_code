#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
class node{
  public:
    int data;
    node* prev=NULL;
    node* next=NULL;
    node(int d){
      data=d;
    }
};
int32_t main(){
  fastio();
  int tc;cin>>tc;
  while(tc--){
    int n;cin>>n;
    vector<vector<node*>> arr(n);
    node* head=NULL;
    node* cur=NULL;
    for(int i=0;i<n;i++){
      int a;cin>>a;
      node* temp=new node(a);
      arr[a].push_back(temp);
      if(head==NULL){head=temp;cur=temp;}
      else{
        temp->prev=cur;
        cur->next=temp;
        cur=cur->next;
      }
    }
    if(arr[0].size()!=1){
      cout<<"No\n";
      continue;
    }
    int flg=1;
    for(int i=n-2;i>=0;i--){
      int cnt=0;
      for(int j=0;j<arr[i].size();j++){
        while(arr[i][j]->prev!=NULL && arr[i][j]->prev->data==i+1){
          arr[i][j]->prev=arr[i][j]->prev->prev;
          if(arr[i][j]->prev!=NULL)arr[i][j]->prev->next=arr[i][j];
          cnt+=1;
        }
        while(arr[i][j]->next!=NULL && arr[i][j]->next->data==i+1){
          arr[i][j]->next=arr[i][j]->next->next;
          if(arr[i][j]->next!=NULL)arr[i][j]->next->prev=arr[i][j];
          cnt+=1;
        }
      }
      if(cnt!=arr[i+1].size()){flg=0;break;}
    }
    if(flg)cout<<"YES\n";
    else cout<<"NO\n";
  }
}