#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
void dfs(vector<vector<int>>& edges,int leaf,vector<int>& vis,vector<int>& ans){
  vis[leaf]=1;
  for(int i=0;i<edges[leaf].size();i++){
    if(vis[edges[leaf][i]])continue;
    dfs(edges,edges[leaf][i],vis,ans);
  }
  ans.push_back(leaf);
}
vector<int> topological_sort(vector<vector<int>>& edges){
  vector<int> vis(edges.size(),0);
  vector<int> ans;
  for(int i=0;i<edges.size();i++){
    if(vis[i])continue;
    dfs(edges,i,vis,ans);
  }
  return ans;
}
vector<vector<int>> scc(vector<vector<int>>& rev,vector<int>& topo){
  vector<int> vis(rev.size(),0);
  vector<vector<int>> ans;
  reverse(topo.begin(),topo.end());
  for(int i=0;i<topo.size();i++){
    if(vis[topo[i]])continue;
    vector<int> temp;
    dfs(rev,topo[i],vis,temp);
    ans.push_back(temp);
  }
  return ans;
}
pair<int,int> func(vector<vector<int>>& edges,vector<vector<int>>& sc,vector<int>& arr){
  reverse(sc.begin(),sc.end());
  int n=edges.size();
  vector<int> info(n);
  vector<vector<int>> sgsm(sc.size(),vector<int>(2,0));
  vector<int> sm(sc.size(),0);
  for(int i=0;i<sc.size();i++){
    for(int j=0;j<sc[i].size();j++){
      sm[i]+=arr[sc[i][j]];
      info[sc[i][j]]=i;
    }
    sgsm[i][0]=sm[i];
    sgsm[i][1]=sc[i].size();
  }
  for(int i=0;i<sc.size();i++){
    for(int j=0;j<sc[i].size();j++){
      for(int k=0;k<edges[sc[i][j]].size();k++){
        int v=edges[sc[i][j]][k];
        if(info[v]!=i && sgsm[info[v]][1]+sc[i].size()>sgsm[i][1]){
          sgsm[i][1]=sgsm[info[v]][1]+sc[i].size();
          sgsm[i][0]=sgsm[info[v]][0]+sm[i];
        }else if(info[v]!=i && sgsm[info[v]][1]+sc[i].size()==sgsm[i][1]){
          sgsm[i][0]=min(sgsm[info[v]][0]+sm[i],sgsm[i][0]);
        }
      }
    }
    // cout<<sgsm[i][0]<<" "<<sgsm[i][1]<<endl;
  }
  int mx=0;int dpmn=1e18;
  for(int i=0;i<sgsm.size();i++){
    if(mx<sgsm[i][1]){
      mx=sgsm[i][1];
      dpmn=sgsm[i][0];
    }else if(mx==sgsm[i][1]){
      dpmn=min(dpmn,sgsm[i][0]);
    }
  }
  return {mx,dpmn};
}
int32_t main(){
  fastio();
  int tc;cin>>tc;
  while(tc--){
    int n,m;
    cin>>n>>m;
    vector<set<int>> e(n);
    vector<set<int>> er(n);
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    for(int i=0;i<m;i++){
      int a,b;
      cin>>a>>b;
      a-=1;b-=1;
      if(a==b)continue;
      e[a].insert(b);
      er[b].insert(a);
    }
    vector<vector<int>> edges(n);
    vector<vector<int>> rev(n);
    for(int i=0;i<n;i++){
      for(auto x:e[i]){
        edges[i].push_back(x);
      }
      for(auto x:er[i]){
        rev[i].push_back(x);
      }
    }
    vector<int> srt=topological_sort(edges);
    // for(int i=0;i<srt.size();i++){
    //   cout<<srt[i]<<" "; 
    // }
    // cout<<endl;
    vector<vector<int>> sc=scc(rev,srt);
    // for(int i=0;i<sc.size();i++){
    //   for(int j=0;j<sc[i].size();j++){
    //     cout<<sc[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }
    pair<int,int> hl=func(edges,sc,arr);
    cout<<hl.first<<" "<<hl.second<<"\n";
  }
}