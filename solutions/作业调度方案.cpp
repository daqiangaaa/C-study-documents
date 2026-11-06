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
        int macc=mac[j][k];
        int len=cost[j][k];
        int t=fin[j];
        while (true) {
    bool ok = true;
    for (int u = t; u < t + len; u++)
        if (busy[macc][u]) { ok = false; break; }
    if (ok) break;
    t++;
}
        for (int u = t; u < t + len; u++) busy[macc][u] = true;
fin[j] = t + len;
cnt[j]++;
    }
    int ans = 0;
for (int j = 0; j < n; j++)
    ans = max(ans, fin[j]);
cout << ans << '\n';
}
