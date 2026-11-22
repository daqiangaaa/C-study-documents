#include <bits/stdc++.h>
using namespace std;
int cnt[5005];
int main(){
    int n;
    long long ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    for(int L=2;L<=5000;L++){
        if(cnt[L]<2)continue;
        long long t=1ll*cnt[L]*(cnt[L]-1)/2;
        for(int i=1;i<=L/2;i++){
            if(i==L-i)ans+=(1ll*cnt[i]*(cnt[i]-1)/2*t%1000000007);
            else ans+=1ll*cnt[i]*cnt[L-i]*t%1000000007;
        }
    }
    ans%=1000000007;
    cout<<ans<<'\n';
}