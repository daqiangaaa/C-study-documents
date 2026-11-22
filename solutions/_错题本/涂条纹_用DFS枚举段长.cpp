#include <bits/stdc++.h>
using namespace std;
int first=1,ans,temp,a[3];
void dfs(int k,int cnt){
    if(cnt==n){
        if(first){ans=temp;first=0;}
        else ans=min(ans,temp);
        temp=0;
        return;
    }
    for(int i=0;i<3;i++)
        for(int j=0;j<a[i];j++)
            for(int z=0;z<m;z++){
                if(i==0&&v[j][z]!='W') temp++;
                if(i==1&&v[i][z]!='B') temp++;
                if(i==2&&v[i][z]!='R') temp++;
            }
    for(int i=1;i<=n-2;i++){ a[k]=i; dfs(i+1,cnt+1); }
}