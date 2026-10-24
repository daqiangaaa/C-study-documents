#include <bits/stdc++.h>
using namespace std;
    vector<int>v;
    int n,m;
bool check(int x){
    long long sum=0;
for(int i=0;i<n;i++){
    if(v[i]>x)sum+=v[i]-x;
}
return sum>=m;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    long long maxH=0;
       for(int i=0;i<n;i++){
        int a;cin>>a;
        v.push_back(a);
        if(a>maxH)maxH=a;
    }
    long long lo=0,hi=maxH,ans=0;
    while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            if(check(mid)){ans=mid;lo=mid+1;}
            else hi=mid-1;
    }
    cout<<ans<<'\n';
}
