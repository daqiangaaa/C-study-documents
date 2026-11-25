#include <bits/stdc++.h>
using namespace std;
int n,m,a[25][25];
long long f[25][25];
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={2,1,-1,-2,-2,-1,1,2};
void ma(const int x,const int y){
    int d=0;
    if(y>=0&&x>=0&&x<=n&&y<=m)
            a[x][y]=1;
    for(int i=0;i<8;i++){
        int nx=x+dx[d];
        int ny=y+dy[d];
        if(ny>=0&&nx>=0&&nx<=n&&ny<=m)
            a[nx][ny]=1;
        d++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x1,y1;
    cin>>n>>m>>x1>>y1;
    ma(x1,y1);
    if(a[0][0]!=1) f[0][0]=1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(a[i][j]!=1){
                if(i>0) f[i][j]+=f[i-1][j];
                if(j>0) f[i][j]+=f[i][j-1];
            }
        }
    }
    cout<<f[n][m]<<'\n';
}