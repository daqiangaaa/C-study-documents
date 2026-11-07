#include <bits/stdc++.h>
using namespace std;
vector<int> qqsort(vector<int> a){
    if(a.size() <= 1) return a;
    int x=a[a.size()/2];
    vector<int> L, E, G;
    for(auto &c:a){
        if(c<x)L.push_back(c);
        else if(c==x)E.push_back(c);
        else G.push_back(c);
    }
    vector<int> res;
    vector<int> left  = qqsort(L);
    vector<int> right = qqsort(G);
    res.insert(res.end(), left.begin(),left.end());
    res.insert(res.end(), E.begin(),E.end());
    res.insert(res.end(), right.begin(),right.end());
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int len=(int)v.size();
    v=qqsort(v);
    for(int i=0;i<len;i++){
        if(i)cout<<' '<<v[i];
        else cout<<v[i];
    }
}