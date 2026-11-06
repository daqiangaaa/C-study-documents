#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    bool first=true;
    for(int i=n;i>=0;i--){
        int a; cin>>a;
        if(a==0) continue;
        if(a>0){ if(!first) cout<<'+'; }
        else { cout<<'-'; a=-a; }
        if(a!=1||i==0) cout<<a;
        if(i>1) cout<<"x^"<<i;
        else if(i==1) cout<<'x';
        first=false;
    }
    if(first) cout<<0;
    cout<<'\n';
}