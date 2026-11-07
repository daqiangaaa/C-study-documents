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
            v[v.size()-1]+=(n-sum);
            break;
        }
    }
    for(int i=0;i<(int)v.size();i++) cout<<v[i]<<' ';
    cout<<'\n';
}