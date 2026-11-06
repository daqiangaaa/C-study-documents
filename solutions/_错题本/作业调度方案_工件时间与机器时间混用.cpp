#include <bits/stdc++.h>
using namespace std;
int ord[405];
int mac[21][21];
int cost[21][21];
int cnt[21];
bool busy[21][8005];
int fin[21];
int main(){
    int m,n; cin>>m>>n;
    for(int i=0;i<n*m;i++) cin>>ord[i];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>mac[i][j];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>cost[i][j];
    for(int i=0;i<n*m;i++){
        int j = ord[i]-1;
        int k = cnt[j];
        int t=fin[mac[j][k]];
        int u;
        for(u=t;u<=cost[j][k]+t;u++){
            busy[mac[j][k]][u]=true;
        }
        fin[mac[j][k]]=u;
        cnt[j]++;
    }
    int max=0;
    for(int i=0;busy[i][0];i++){
        int aaa=0;
        for(int j=0;busy[i][j];j++){
            aaa++;
        }
        if(aaa>max)max=aaa;
    }
    cout<<max;
}