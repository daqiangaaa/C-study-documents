#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,b;
    cin>>n>>b;
    vector<int>v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end(),greater<int>());
    int sum=0,ans=0;
    for(auto &c:v){
        ans++;
        if(sum+c>=b){break;}
        else {sum+=c;}
    }
    cout<<ans;
}