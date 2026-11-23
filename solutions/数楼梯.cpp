#include <bits/stdc++.h>
using namespace std;
vector<int> add(vector<int>&a,vector<int>&b){
    vector<int>c;
    int n=max(a.size(),b.size());
    int carry=0;
    for(int i=0;i<n||carry;i++){
        int t=carry;
        if(i<(int)a.size())
            t+=a[i];
        if(i<(int)b.size())
            t+=b[i];
        c.push_back(t%10);
        carry=t/10;
    }
    if(c.empty())c.push_back(0);
    return c;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> f[5005];
    int n;
    cin>>n;
    f[1]=vector<int>(1,1);
    f[2]=vector<int>(1,2);
    for(int i=3;i<=n;i++){
        f[i]=add(f[i-1],f[i-2]);
    }
    for(int j=(int)f[n].size()-1;j>=0;j--){
        cout<<f[n][j];
    }
    cout<<'\n';
}