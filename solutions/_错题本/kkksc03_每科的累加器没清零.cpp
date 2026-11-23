#include <bits/stdc++.h>
using namespace std;
int best=INT_MAX,ans=0,a[25],n,s=0;
void dfs(int k,int l){
    if(k==n){best=min(best,max(l,s-l));return;}
    dfs(k+1,l+a[k]);
    dfs(k+1,l);
}
int main(){
    int t[4];
    for(int i=0;i<4;i++){ cin>>t[i]; }
    for(int i=0;i<4;i++){
        n=t[i];
        for(int j=0;j<n;j++){ cin>>a[j]; s+=a[j]; }
        dfs(0,0);
        ans+=best;
        best=0;
    }
    cout<<ans<<'\n';
}