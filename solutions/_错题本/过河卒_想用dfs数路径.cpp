#include <bits/stdc++.h>
using namespace std;
int n,m,a[25][25];
long long ans=0;
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={2,1,-1,-2,-2,-1,1,2};
void ma(const int x,const int y){
    int d=0;
    if(y>=0&&x>=0&&x<n&&y<m) a[x][y]=1;
    for(int i=0;i<8;i++){ int nx=x+dx[d]; int ny=y+dy[d];
        if(ny>=0&&nx>=0&&nx<n&&ny<m) a[nx][ny]=1; d++; }
}
void dfs(int x,int y){
    if(x>n||y>m)return;
    if(a[x][y]==1)return;
    if(x==n&&y==m){ans++;return;}
    dfs(x+1,y); dfs(x,y+1);
}
int main(){ int x1,y1; cin>>n>>m>>x1>>y1; ma(x1,y1); dfs(0,0); cout<<ans<<'\n'; }