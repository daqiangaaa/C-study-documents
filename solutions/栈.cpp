#include <bits/stdc++.h>
using namespace std;
long long f[25];
int main(){
    int n;
    cin>>n;
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            f[i]+=f[j]*f[i-1-j];
        }
    }
    cout<<f[n]<<'\n';
}