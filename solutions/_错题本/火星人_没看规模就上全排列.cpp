#include <bits/stdc++.h>
using namespace std;
int used[10005];
int a[10005],n,m,ans,ok,des[10005];
void dfs(int cnt){
    if(cnt==n){
        if(a==des)ok=1;
        if(ok)
        ans++;
        if(ans==m)
            for(int i=0;i<n;i++)
                cout<<a[i]<<' ';
        return;
    }
    for(int i=1;i<=n;i++){
        if(used[i])continue;
        used[i]=1;
        dfs(cnt++);
        used[i]=0;
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>des[i];
    dfs(0);
    return 0;
}