#include <bits/stdc++.h>
using namespace std;
int a[505][505];
int b[505][505];
void rot90(int xx,int yy,int len,int zz){
    int nn=len*2+1;
    for(int i=xx-len;i<=nn+xx;i++){
        for(int j=yy-len;j<=nn+yy;j++){
            if(zz==0)b[i][j]=a[nn-j][i];
            if(zz==1)b[i][j]=a[j][nn-i];
        }
    }
}
int main()
{
    int n,m,x,y,r,z,cnt=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=cnt;
            b[i][j]=cnt;
            cnt++;
            }
        }
    for(int k=1;k<=m;k++){
        cin>>x>>y>>r>>z;
        rot90(x,y,r,z);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<b[i][j]<<' ';
        }
        cout<<'\n';
    }
}