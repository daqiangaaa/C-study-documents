#include <bits/stdc++.h>
using namespace std;
int w[3505],d[3505],f[12905];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>w[i]>>d[i];
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            f[j]=max(f[j],f[j-w[i]]+d[i]);
        }
    }
    cout<<f[m]<<'\n';
}