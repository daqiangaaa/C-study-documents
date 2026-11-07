#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>v;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int len=(int)v.size();
    sort(v.begin(),v.begin()+len);
    for(int i=0;i<len;i++){
        if(i)cout<<' '<<v[i];
        else cout<<v[i];
    }
}