#include <bits/stdc++.h>
using namespace std;
string rev(string s){
    reverse(s.begin(),s.end());
    int i=0;
    while(i+1<(int)s.size()&&s[i]=='0')
        ++i;
    return s.substr(i);
}
string revTail(string t){
    reverse(t.begin(),t.end());
    while(t.back()=='0'&&t.size() > 1){
    t.pop_back();
    }
    return t;
}
int main(){
    string s;
    cin>>s;
    string ans;
    int kind=0;
    if(s.back()=='%')kind=3;
    else if(s.find('/')!=string::npos)kind=2;
    else if(s.find('.')!=string::npos)kind=1;
    else kind=0;
    switch(kind){
        case 3:{
        s.pop_back();
        s=rev(s);
        cout<<s<<"%"<<'\n';
        break;}
        case 2:{
        size_t d=s.find('/');
        string a=s.substr(0,d);
        string b=s.substr(d+1);
        a=rev(a);
        b=rev(b);
        cout<<a<<"/"<<b<<'\n';
            break;}
        case 1:{
        size_t d=s.find('.');
        string a=s.substr(0,d);
        string b=s.substr(d+1);
        a=rev(a);
        b=revTail(b);
        cout<<a<<"."<<b<<'\n';
            break;}
        case 0:{
        s=rev(s);
        cout<<s<<'\n';}
    }
}
