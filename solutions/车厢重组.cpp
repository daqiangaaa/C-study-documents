#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[1005];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
}