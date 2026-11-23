#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
void dfs(int k){
    if(k==n){ans++;return;}
    if(k>n)return;
    dfs(k+1);
    dfs(k+2);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    dfs(0);
    cout<<ans<<'\n';
}