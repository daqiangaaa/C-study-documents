#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v;
    v.push_back(2);
    int sum=2;
    for(int i=3;i<n;i++){
        if(i+sum<=n){
            sum+=i;
            v.push_back(i);
        }
        else {
            int yu=n-sum;
            int a=(int)v.size();
            int j=a-1;
            while(yu>0){
                v[j--]++;
                yu--;
                if(j<0)j=a-1;
            }
            break;
        }
    }
    int len=(int)v.size();
    for(int i=0;i<len;i++){
        if(i)cout<<' '<<v[i];
        else cout<<v[i];
    }
    cout<<'\n';
    vector<int>fact(10005,0);
    fact[0]=1;
    int cnt=1;
    for(int i=0;i<len;i++){
        int carry=0;
        for(int j=0;j<cnt;j++){
            long long temp=fact[j]*v[i]+carry;
            fact[j]=temp%10;
            carry=temp/10;
        }
        while(carry){
            fact[cnt++]=carry%10;
            carry/=10;
        }
    }
    for(int i=0;i<cnt||fact[i];i++){
        if(fact[i]>=10){
            fact[i+1]+=fact[i]/10;
            fact[i]%=10;
        }
        if(i>=cnt){
            cnt++;
        }
    }
    for(int i=cnt-1;i>=0;i--){
        cout<<fact[i];
    }
}