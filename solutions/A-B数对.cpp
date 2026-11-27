#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,c;
    cin>>n>>c;
    vector<int>v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.begin()+n);
    long long ans=0;
    for(int i=0;i<n;i++){
        ans+=upper_bound(v.begin(),v.end(),v[i]+c)-lower_bound(v.begin(),v.end(),v[i]+c);
    }
    cout<<ans<<'\n';
}