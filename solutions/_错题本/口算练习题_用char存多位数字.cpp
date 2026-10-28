#include <bits/stdc++.h>
using namespace std;
void solve(char x,char a,char b){
    string s;
    int t;
    if(x=='a'){
        t=(a-'0')+(b-'0');
        cout<<a<<"+"<<b<<"="<<t<<'\n';
        s=a+b+(string)t;
        cout<<(int)s.size()+2<<'\n';
    }
    if(x=='b'){
        t=(a-'0')-(b-'0');
        cout<<a<<"-"<<b<<"="<<t<<'\n';
        s=a+b+(string)t;
        cout<<(int)s.size()+2<<'\n';
    }
    if(x=='c'){
        t=(a-'0')*(b-'0');
        cout<<a<<"*"<<b<<"="<<t<<'\n';
        s=a+b+(string)t;
        cout<<(int)s.size()+2<<'\n';
    }
}
int main()
{
    int n;
    cin>>n;
    char a,b;
    while(n--){
        char z,c;
        cin>>z;
        if(z>='a'&&z<='c'){
            c=z;
            cin>>a>>b;
        }
        else {
            cin>>b;
            a=z;
        }
        solve(c,a,b);
    }
    return 0;
}