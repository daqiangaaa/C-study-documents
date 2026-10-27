#include <bits/stdc++.h>
using namespace std;
char a[12][12];
char b[12][12];
char jieguo[12][12];
char zhongjian[12][12];
int n;
void rot90(int src[12][12],int dst[12][12]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dst[i][j]=src[n-1-j][i];
        }
    }
}
void mirror(int src[12][12],int dst[12][12]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dst[i][j]=src[i][n-1-j];
        }
    }
}
bool check(int x[12][12],int y[12][12]){
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(x[i][j]!=y[i][j])return false;
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
    char c[12][12],d[12][12],t[12][12];
    rot90(a,b);if(check(b,jieguo)){puts('1');return 0;}
    rot90(b,c);if(check(c,jieguo)){puts('2');return 0;}
    rot90(c,d);if(check(d,jieguo)){puts('3');return 0;}
    mirror(a,t);if(check(b,jieguo)){puts('4');return 0;}
    rot90(t,b);if(check(b,jieguo)){puts('5');return 0;}
    rot90(b,c);if(check(c,jieguo)){puts('5');return 0;}
    rot90(c,d);if(check(d,jieguo)){puts('5');return 0;}
    if(check(a,jieguo)){puts('6');return 0;}
    cout<<"7"<<'\n';
    return 0;
}