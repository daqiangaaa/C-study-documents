#include <bits/stdc++.h>
using namespace std;
int n,k,ans;
vector<int> v;
bool isprime(int x){
    if(x<2) return false;
    for(int i=2;i*i<=x;i++)
        if(x%i==0) return false;
    return true;
}
void solve(int start,int cnt,int sum){
    if(cnt==k){ if(isprime(sum)) ans++; return; }
    for(int i=start;i<n;i++) solve(i+1,cnt+1,sum+v[i]);
}
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){ int a; cin>>a; v.push_back(a); }
    solve(0,0,0);
    cout<<ans<<'\n';
}