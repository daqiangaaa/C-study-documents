#include <bits/stdc++.h>
using namespace std;
int trans(int x){
    int result=0,cnt=0,a[105];
    while(x/10){
        a[cnt]=x%10;
        x/=10;
        cnt++;
    }
    a[cnt]=x;
    for(int i=0;i<=cnt;i++){
        if(a[i]==0)result+=6;
        if(a[i]==1)result+=2;
        if(a[i]==2)result+=5;
        if(a[i]==3)result+=5;
        if(a[i]==4)result+=4;
        if(a[i]==5)result+=5;
        if(a[i]==6)result+=6;
        if(a[i]==7)result+=3;
        if(a[i]==8)result+=7;
        if(a[i]==9)result+=6;
    }
    return result;
}
int n,ans=0;
int main(){
    cin>>n;
    for(int i=0;i<1005;i++){
        for(int j=0;j<1005;j++){
            if(trans(i)+trans(j)+trans(i+j)==n-4)
                ans++;
        }
    }
    cout<<ans<<'\n';
}