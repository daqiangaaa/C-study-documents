#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n,q;
    vector<int>v;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    while(q--){
        int a;
        cin>>a;
        int lo=0;
        int hi=v.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(v[mid]==a){
                cout<<mid<<'\n';break;
            }
            else if(v[mid]<a)lo=mid+1;
            else hi=mid-1;
        }
        if(lo>hi)cout<<"-1"<<'\n';
    }
}
