#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,c;
    cin>>n>>c;
    vector<int>v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int pos=lower_bound(v.begin(),v.end(),v[i]+c)-v.begin();
        while(v[pos]==v[i]+c){
            ans++;
            pos++;
        }
    }
    cout<<ans<<' ';
}