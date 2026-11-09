#include <bits/stdc++.h>
using namespace std;
int cnt[10005];
int main(){
    int a,n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        cnt[a]++;
    }
    int ans=0;
    for(int i=0;i<1005;i++){
        if(cnt[i]>=1)ans++;
    }
    cout<<ans<<'\n';
    for(int i=0;i<1005;i++){
        if(cnt[i]>=1)cout<<i<<' ';
    }
}