#include <bits/stdc++.h>
using namespace std;
int main()
{
    string A,B;
    cin>>A>>B;
    vector<int>a;
    vector<int>b;
    for(int i=(int)A.size()-1;i>=0;i--)a.push_back(A[i]-'0');
    for(int i=(int)B.size()-1;i>=0;i--)b.push_back(B[i]-'0');
    int na=(int)a.size();
    int nb=(int)b.size();
    vector<int>v(na+nb,0);
    for(int i=0;i<na;i++){
        for(int j=0;j<nb;j++){
            v[i+j]+=a[i]*b[j];
        }
    }
    for (int k=0;k<(int)v.size()-1;k++){
        v[k+1]+=v[k]/10;
        v[k]%=10;
    }
    while (v.size()>1 && v.back()==0) v.pop_back();
    for(int i=(int)v.size()-1;i>=0;i--) cout<<v[i];
    cout<<'\n';
    return 0;
}