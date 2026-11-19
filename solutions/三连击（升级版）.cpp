#include <bits/stdc++.h>
using namespace std;
int A,B,C,judge;
void solve(){
    for(int a=123;a<=987;a++){
        if(a*B%A)continue;
        if(a*C%A)continue;
        int b=a*B/A;
        int c=a*C/A;
        if(b>987||c>987||c<123||b<123)continue;
        int vis[10]={0};
        int t[3]={a,b,c};
        bool ok=true;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){
                int d=t[i]%10;
                t[i]/=10;
                if(d==0||vis[d])ok=false;
                vis[d]++;
            }
        if(ok){
            cout<<a<<' '<<b<<' '<<c<<'\n';
            judge=1;
        }
    }
}
int main(){
    cin>>A>>B>>C;
    if(A==0){ cout<<"No!!!\n"; return 0; }
    solve();
    if(!judge) cout<<"No!!!\n";
}