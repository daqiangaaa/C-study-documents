#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v;
bool check(long long x)
{
    int qieduan=1;
    long long sum=0;
    int i;
    for(i=0;i<(int)v.size();i++){
            if(v[i]>x)return false;
            sum+=v[i];
            if(sum>x){
                sum=0;
                i--;
                qieduan++;
            }
    }
    if(qieduan>m)return false;
    else return true;
}
int main()
{
    cin>>n>>m;
    int best=0;
    long long sum=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        sum+=a;
        v.push_back(a);
        if(a>best)best=a;
    }
    long long lo=0,hi=sum,ans=sum;
    while(lo<=hi){
        long long mid=lo+(hi-lo)/2;
    if(check(mid)){ans=mid;hi=mid-1;}
    else lo=mid+1;
    }
    cout<<ans<<'\n';
}
