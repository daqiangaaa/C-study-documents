#include <bits/stdc++.h>
using namespace std;
int a[1030][1030];
void solve(int x,int y,int len){
    for(int i=x;i<len/2;i++){
        for(int j=x;j<len/2;j++){
            a[i][j]=1;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int t=pow(2,n);
    int te=t;
    int xx,yy;
    xx=t/2;
    yy=t/2;
        while(t!=1){
            solve(xx,yy,t);
            t=t/2;
            xx/=2;
            yy/=2;
        }
    for(int i=1;i<=te;i++){
        for(int j=1;j<=te;j++){
            a[i][j]^=1;
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
}