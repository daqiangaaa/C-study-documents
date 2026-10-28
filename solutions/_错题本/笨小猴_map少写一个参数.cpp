#include <bits/stdc++.h>
using namespace std;
bool isprime(int x){
    if(x<2)return false;
    else if(x==2)return true;
    else { for(int i=2;i*i<=x;i++){ if(x%i==0)return false; } }
    return true;
}
int main(){
    string s; cin>>s;
    map<int>mp;
    for(int i=0;i<(int)s.size();i++){ mp[s[i]]++; }
    if(isprime(mp.max()-mp.min()))cout<<"Lucky Word"<<'\n'<<mp.max()-mp.min()<<'\n';
    else cout<<"No Answer"<<'\n'<<"0"<<'\n';
}