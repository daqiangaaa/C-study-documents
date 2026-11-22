#include <bits/stdc++.h>
using namespace std;
vector<string>v;
int r,c,k;
bool heng(int a,int b){
    if(c-b<k)return false;
    for(int i=b;i<k+b;i++){
        if(v[a][i]=='#')return false;
    }
    return true;
}
bool shu(int a,int b){
    if(r-a<k)return false;
    for(int i=a;i<k+a;i++){
        if(v[i][b]=='#')return false;
    }
    return true;
}
int main(){
    cin>>r>>c>>k;
    string s;
    for(int i=0;i<r;i++){
        cin>>s;
        v.push_back(s);
    }
    int ans=0;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            if(heng(i,j))ans++;
            if(shu(i,j))ans++;
        }
    if(k==1)ans/=2;
    cout<<ans<<'\n';
}