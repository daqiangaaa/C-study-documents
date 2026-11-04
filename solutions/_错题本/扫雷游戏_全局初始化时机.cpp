#include <bits/stdc++.h>
using namespace std;
int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={1,1,0,-1,-1,-1,0,1};
int n1,n2;
vector<vector<char>>a(n1+2,vector<char>(n2+2,'?'));
void solve(const int x,const int y,char &c){
    if(c=='*')return;
    int d=0,cnt=0;
    while(d<8){if(a[dx[d]+x][dy[d]+y]=='*'){ cnt++; } d++;}
    c=cnt+'0';
}
int main(){
    cin>>n1>>n2;
    for(int i=1;i<=n1;i++) for(int j=1;j<=n2;j++) cin>>a[i][j];
    for(int i=1;i<=n1;i++){ for(int j=1;j<=n2;j++){ solve(i,j,a[i][j]); cout<<a[i][j]; } cout<<'\n'; }
}