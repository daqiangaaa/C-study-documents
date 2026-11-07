#include <bits/stdc++.h>
using namespace std;
int kth(vector<int> a,int k){
    if(a.size() == 1) return a[0];

    int x = a[a.size()/2];

    vector<int> L, E, G;
    for(int c : a){
        if(c < x)       L.push_back(c);
        else if(c == x) E.push_back(c);
        else            G.push_back(c);
    }
    if(k < (int)L.size())          return kth(L,k);
    if(k <(int)L.size()+(int)E.size())     return x;
    return kth(G, k-(int)L.size()-(int)E.size());
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k,n;
    cin>>n>>k;
    vector<int>v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    cout<<kth(v,k);
}