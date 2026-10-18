#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int fact[100]={1};
    int sum[100]={0};
    int fact_len=1;
    int sum_len=1;
    for(int i=1;i<=n;i++){
        int carry=0;
        for(int j=0;j<fact_len;j++){
            int temp=fact[j]*i+carry;
            fact[j]=temp%10;
            carry=temp/10;
        }
        while(carry>0){
            fact[fact_len]=carry%10;
            carry/=10;
            fact_len++;
        }
        carry=0;
        for(int j=0;j<max(fact_len,sum_len);j++){
            int temp=sum[j]+fact[j]+carry;
            sum[j]=temp%10;
            carry=temp/10;
        }
        if(carry>0){
            sum[sum_len]=carry;
            sum_len++;
        }
        sum_len=max(sum_len,fact_len);
    }
    for(int i=sum_len-1;i>=0;i--){
        cout<<sum[i];
    }
    cout<<endl;
    return 0;
}
