#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    long long squ=0;
    for(int i=1;i<=min(n,m);i++)
        squ+=1LL*(n-i+1)*(m-i+1);
    long long a=1LL*(n+1)*n/2;
    long long b=1LL*(m+1)*m/2;
    cout<<squ<<' '<<a*b-squ<<'\n';
}
