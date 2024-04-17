#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastio(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); 
}
int p;
vector<int> arr(5001);
int modInverse(int A, int M) { 
    int m0 = M; 
    int y = 0, x = 1; 
    if (M == 1) 
        return 0; 
    while (A > 1) { 
        int q = A / M; 
        int t = M; 
        M = A % M, A = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    }
    if (x < 0) 
        x += m0; 
    return x; 
} 
void calc(){
    arr[0]=1;
    for(int i=1;i<5001;i++){
        arr[i]=i*arr[i-1];
        arr[i]%=p;
    }
}
int comb(int n,int r){
    int d=arr[n-r]*arr[r];
    d%=p;
    d=modInverse(d,p);
    d=arr[n]*d;
    return (d%p);
}
int32_t main(){
    int n;
    cin>>n>>p;
    calc();
    int cnt=0;
    if(n%2==0)cnt=arr[n-2];
    int st=(n-1)/2;
    for(int i=st;i>0;i--){
        int m=(n-1)-i;
        int l=(i+1);
        if(n%2!=0)l-=1;
        for(int j=0;j<i;j++){
            int vl=comb(i-1,j);
            int sm=(vl*arr[m+j-1])%p;
            sm=(sm*l)%p;
            cnt=(cnt+sm)%p;
        }
    }
    cnt=(cnt*n)%p;
    cout<<cnt<<"\n";
}