#include <bits/stdc++.h>
using namespace std;
int a[505][505], b[505][505];

void rot90(int x,int y,int r,int z){
    for(int i=x-r;i<=x+r;i++)
        for(int j=y-r;j<=y+r;j++)
            b[i][j] = (z==0) ? a[x+y-j][y+i-x] : a[x+j-y][x+y-i];
    for(int i=x-r;i<=x+r;i++)
        for(int j=y-r;j<=y+r;j++)
            a[i][j] = b[i][j];
}

int main(){
    int n,m,x,y,r,z;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j] = (i-1)*n + j;
    while(m--){
        cin>>x>>y>>r>>z;
        rot90(x,y,r,z);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}