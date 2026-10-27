#include <bits/stdc++.h>
using namespace std;
char a[12][12];
char b[12][12];
char jieguo[12][12];
char zhongjian[12][12];
int n;
void rot90(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            b[i][j]=a[n-1-j][i];
        }
    }
}
void mirror(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            b[i][j]=a[i][n-1-j];
        }
    }
}
bool check(){
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(b[i][j]!=jieguo[i][j])return false;
        }
    }
    return true;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>jieguo[i][j];
        }
    }
    if(check()){cout<<"6"<<'\n';return 0;}
    int ok=1;
    int judge=3;
    while(judge--){
    rot90();
    if(check()){
        cout<<ok<<'\n';
        return 0;
    }
        ok++;
    }
    rot90();
    mirror();
    if(check()){cout<<"4"<<'\n';return 0;}
    judge=3;
    while(judge--){
    rot90();
    if(check()){
        cout<<"5"<<'\n';
        return 0;
    }
    }
    cout<<"7"<<'\n';
    return 0;
}