#include <bits/stdc++.h>
using namespace std;
vector<int> v;
map<int,int> mp;
int main(){
    int a,b,n;
    cin>>n;
    cin>>b;
    while(cin>>a){
        v.push_back(abs(a-b));
        b=a;
    }
    int ok=1;
    for(int i=0;i<n-1;i++){
        mp[v[i]]++;
    }
    for(int i=1;i<n;i++){
        if(mp[i]<1){ ok=0; break; }
    }
    if(ok) cout<<"Jolly"<<'\n';
    else cout<<"Not jolly"<<'\n';
}