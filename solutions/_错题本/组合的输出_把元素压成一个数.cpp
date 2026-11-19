#include <bits/stdc++.h>
using namespace std;
int n,r;
void dfs(int start,int cnt,long long sum){
    if(cnt==r){
        for(int i=0;i<cnt;i++){
            cout<<setw(3)<<sum%10;
            sum/=10;
        }
        cout<<'\n';
    }
    for(int i=start;i<=n;i++)dfs(i+1,cnt+1,sum+i*pow(10,cnt));
}
int main(){
    cin>>n>>r;
    if(r==0)return 0;
    dfs(1,0,0);
}