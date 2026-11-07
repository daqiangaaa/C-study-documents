#include <bits/stdc++.h>
using namespace std;
vector<int>v(505);
int main(){
    int p;
    cin>>p;
    v[0]=1;
    int digits=(int)(p*log10(2.0)+1);
    cout<<digits<<'\n';
    int cnt=1;
    int pp=30;
    long long carry=0;
    for(int i=0;i<p;i+=pp){
        pp=min(30,p-i);
        for(int j=0;j<cnt&&j<500;j++){
            long long mul=1LL << pp;
            long long temp=v[j]*mul+carry;
            v[j]=temp%10;
            carry=temp/10;
        }
        while(carry&&cnt<500){
            v[cnt++]=carry%10;
            carry/=10;
        }
    }
    v[0]--;
    for(int i=0;i<500;i++){
        cout<<v[499-i];
        if((i+1)%50==0)cout<<'\n';
    }
}