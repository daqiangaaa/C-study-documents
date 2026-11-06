#include <bits/stdc++.h>
using namespace std;
int solve(int x,int y){
    vector<int>v(3000);
    v[0]=1;
    int carry=0,cnt=1;
    for(int i=1;i<=x;i++){
        for(int j=0;j<cnt;j++){
            int temp=v[j]*i+carry;
            v[j]=temp%10;
            carry=temp/10;
        }
        while(carry){
            v[cnt]=carry%10;
            cnt++;
            carry/=10;
        }
    }
    int ans=0;
    for(int i=0;i<cnt;i++){
        if(v[i]==y)ans++;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        cout<<solve(a,b)<<'\n';
    }
}