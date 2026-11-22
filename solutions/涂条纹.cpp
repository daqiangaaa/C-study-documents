#include <bits/stdc++.h>
using namespace std;
int trans(char a){
    if(a=='W')return 0;
    if(a=='B')return 1;
    return 2;
}
int cost[55][3];
int main(){
    int n,m;
    cin>>n>>m;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            cost[i][trans(s[j])]++;
        }
    }
    int ans=0,first=1;
    for(int i=1;i<=n-2;i++)
        for(int j=i+1;j<=n-1;j++){
            int cw=0,cb=0,cr=0;
            for(int k=0;k<i;k++)cw+=cost[k][0];
            for(int k=i;k<j;k++)cb+=cost[k][1];
            for(int k=j;k<n;k++)cr+=cost[k][2];
            int s=i*m-cw+(j-i)*m-cb+(n-j)*m-cr;
            if(first){ans=s;first=0;}
            else ans=min(ans,s);
        }
    cout<<ans;
}