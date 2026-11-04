#include <bits/stdc++.h>
using namespace std;
vector<int>a;
vector<int>b;
vector<int>v;
int main(){
    string A,B;
    cin>>A>>B;
    for(int i=(int)A.size()-1;i>=0;i--)a.push_back(A[i]-'0');
    for(int i=(int)B.size()-1;i>=0;i--)b.push_back(B[i]-'0');
    int n=max((int)a.size(),(int)b.size());
    a.resize(n+1,0);
    b.resize(n+1,0);
    int carry=0;
    for(int i=0;i<n+1;i++){
        int t=a[i]+b[i]+carry;
        carry=t/10;
        v.push_back(t%10);
    }
    int ok=0;
    if((int)v.size()==2&&v[0]==0){
        cout<<0<<'\n';
        return 0;
    }
    for(int i=(int)v.size();i>=0;i--){
        if(v[i]==0&&!ok)continue;
        ok=1;
        cout<<v[i];
    }
    cout<<'\n';
    return 0;
}