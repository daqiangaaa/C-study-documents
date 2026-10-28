#include <bits/stdc++.h>
using namespace std;
string solve1(string s1,string s2){
    string s;
        s=s1+s2;return s;
}
string solve2(string s1,int a,int b){
    string s;
    for(int i=a;i<=b;i++){
        s+=s1[i];
    }
    return s;
}
string solve3(string s1,int a,string s2){
    string s;
    for(int i=0;i<(int)s1.size();i++){
        s+=s1[i];
        if(i==a)s+=s2;
    }
    return s;
}
int solve4(string s1,string s2){
    int cnt=0;
    for(int i=0;i<(int)s1.size();i++){
        if(s1[i]==s2[cnt]){
            cnt++;
        }
        else cnt=0;
        if(cnt==(int)s2.size())return i-cnt;
    }
}
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    while(n--){
        int a;
        cin>>a;
        if(a==1){
            string s2;
            cin>>s2;
            s=solve1(s,s2);
            cout<<s<<'\n';
        }
        if(a==2){
            int a,b;
            cin>>a>>b;
            s=solve2(s,a,b);
            cout<<s<<'\n';
        }
        if(a==3){
            int a;
            string s2;
            cin>>a>>s2;
            s=solve3(s,a,s2);
            cout<<s<<'\n';
        }
        if(a==4){
            string s2;
            int a;
            cin>>s2;
            a=solve4(s,s2);
            cout<<a<<'\n';
        }
    }
    return 0;
}