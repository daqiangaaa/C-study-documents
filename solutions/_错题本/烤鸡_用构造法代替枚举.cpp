#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<10||n>30){ cout<<0<<'\n'; return 0; }
    int cnt=0;
    vector<int> v(10,1);
    int t=n-10;
    for(int d=0;d<20;d++){
        for(int i=0;t>0;i++){
            t-=1;
            if(10-i-d>=0) v[10-i-d]++;
            else i=0;
        }
        for(auto &c:v){ cout<<c<<' '; }
        cout<<'\n';
        int cnt++;
    }
}