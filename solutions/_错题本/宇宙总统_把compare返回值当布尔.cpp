#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,id=1;
    cin>>n;
    string a,best;
    cin>>a;
    best=a;
    for(int i=1;i<n;i++){
        cin>>a;
        if(a.compare(best)){best=a;id=i+1;}
    }
    cout<<id<<'\n'<<best;
}