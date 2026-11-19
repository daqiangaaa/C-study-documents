#include <bits/stdc++.h>
using namespace std;
int A,B,C,judge;
int vis[10];
void solve(){
    for(int a=123;a<=987;a++){
        if(a*B%A)continue;
        if(a*C%A)continue;
        int b=a*B/A;
        int c=a*C/A;
        if(b>987||c>987||c<123||b<123)break;
        int n=3;
        while(n--){
            vis[a%10]++; a/=10;
            vis[b%10]++; b/=10;
            vis[c%10]++; c/=10;
        }
        if(vis[0])continue;
        int ok=1;
        for(auto &s:vis){ if(s!=1)ok=0; }
        if(ok){ cout<<a<<' '<<b<<' '<<c<<'\n';judge=1; }
        else continue;
    }
}
int main(){
    cin>>A>>B>>C;
    if(A==0)cout<<"No!!!";
    solve();
    if(!judge)cout<<"No!!!";
}