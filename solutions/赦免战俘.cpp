#include <bits/stdc++.h>
using namespace std;
int a[1030][1030];
void f(int x, int y, int len){
    if (len == 1) return;
    int h = len / 2;
    for (int i = x; i < x + h; ++i)
        for (int j = y; j < y + h; ++j)
            a[i][j] = 1;
    f(x + h, y,     h);
    f(x,     y + h, h);
    f(x + h, y + h, h);
}
int main(){
    int n;
    cin>>n;
    int t=pow(2,n);
    int te=t;
    int xx,yy;
    xx=1;
    yy=1;
    f(xx,yy,t);
    for(int i=1;i<=te;i++){
        for(int j=1;j<=te;j++){
            a[i][j]^=1;
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
}