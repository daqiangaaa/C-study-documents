#include <bits/stdc++.h>
using namespace std;
struct stu{ int id; string name; };
int main(){
    int n,m; cin>>n>>m;
    stu v[10005];
    for(int i=0;i<n;i++) cin>>v[i].id>>v[i].name;
    int a,b,d=0;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        if(a^v[d].id==0){ d-=b; } else d+=b;
        if(d<0)d+=n;
        if(d>=n)d-=n;
    }
    cout<<v[d].name;
}