#include <bits/stdc++.h>
using namespace std;
int cnt[1005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        cnt[a]++;
    }
    bool first=true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<cnt[i];j++){
            if(first){cout<<i;first=false;}
            else cout<<' '<<i;
        }
    }
}