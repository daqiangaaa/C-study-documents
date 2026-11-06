#include <bits/stdc++.h>
using namespace std;
void solve(int a,int b,int c,char s1,char s2){
    vector<char>v;
    char word;
    if(a==1){
        for(int i=1;i<s2-s1;i++){
            word=s1+i;
            v.push_back(word);
        }
    }
    else if(a==2){
        for(int i=1;i<s2-s1;i++){
            word=s1+i;
            if(word>='a'||word<='z')word=word+'A'-'a';
            v.push_back(word);
        }
    }
    else {
        for(int i=1;i<s2-s1;i++){
            v.push_back('*');
        }
    }
    int n=(int)v.size();
    if(c==1){
    for(int i=0;i<n;i++){
        for(int j=0;j<b;j++){
            cout<<v[i];
        }
    }
    }
    else {
        for(int i=n-1;i>=0;i--){
        for(int j=0;j<b;j++){
            cout<<v[i];
        }
    }
    }
}
int main(){
    int p1,p2,p3;
    cin>>p1>>p2>>p3;
    string line;
    cin>>line;
    int n=(int)line.size();
    for(int i=0;i<n;i++){
        if(line[i]=='-'){
            if(line[i+1]-line[i-1]<=0){cout<<'-';}
            else if(line[i+1]-line[i-1]==1){;}
            else solve(p1,p2,p3,line[i-1],line[i+1]);
        }
        else cout<<line[i];
    }
}