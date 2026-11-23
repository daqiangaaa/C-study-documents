#include <bits/stdc++.h>
using namespace std;
int ans=INT_MAX,n,a[15],b[15],k,suan=1,ku;
void dfs(int start,int cnt){
    if(cnt==k){
        int t=abs(suan-ku);
        if(t<ans) ans=t;
        return;
    }
    for(int i=start;i<n;i++){
        suan*=a[i];
        ku+=b[i];
        dfs(i+1,cnt+1);
        suan=1;
        ku=0;
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){ cin>>a[i]>>b[i]; }
    for(k=1;k<=n;k++){ dfs(0,0); }
    cout<<ans<<'\n';
}