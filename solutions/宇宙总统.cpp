#include <bits/stdc++.h>
using namespace std;
bool judge(string &x,string &y){
    if(x.size()!=y.size())return x.size()>y.size();
    return x>y;
}
int main(){
    int n,id=1;
    cin>>n;
    string a,best;
    cin>>a;
    best=a;
    for(int i=1;i<n;i++){
        cin>>a;
        if(judge(a,best)){best=a;id=i+1;}
    }
    cout<<id<<'\n'<<best;
}