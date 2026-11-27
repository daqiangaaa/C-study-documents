#include <bits/stdc++.h>
using namespace std;
int T,M,t[105],v[105],f[1005];
int main(){
    cin>>T>>M;
    for(int i=1;i<=M;i++)cin>>t[i]>>v[i];
    for(int i=1;i<=M;i++){
        for(int j=T;j>=t[i];j--){
            f[j]=max(f[j],f[j-t[i]]+v[i]);
        }
    }
    cout<<f[T]<<'\n';
}