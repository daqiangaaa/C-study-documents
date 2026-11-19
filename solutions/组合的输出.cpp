#include <bits/stdc++.h>
using namespace std;
int n,r;
int a[25];
void dfs(int start,int cnt){
    if(cnt==r){
        for(int i=0;i<cnt;i++) cout<<setw(3)<<a[i];
        cout<<'\n';
    }
    for(int i=start;i<=n;i++){ a[cnt]=i; dfs(i+1,cnt+1); }
}
int main(){
    cin>>n>>r;
    if(r==0){ cout<<'\n'; return 0; }
    dfs(1,0);
}