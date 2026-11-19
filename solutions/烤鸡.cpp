#include <bits/stdc++.h>
using namespace std;
int a[10];
int n,cnt=0,ok=0;
void dfs(int k,int sum){
    if(k==10){
        if(sum==n){
            if(ok){ for(auto &c:a) cout<<c<<' '; cout<<'\n'; }
            else cnt++;
        }
        return;
    }
    for(int i=1;i<=3;i++){ a[k]=i; dfs(k+1,sum+i); }
}
int main(){
    cin>>n;
    dfs(0,0);
    cout<<cnt<<'\n';
    ok=1;
    dfs(0,0);
}