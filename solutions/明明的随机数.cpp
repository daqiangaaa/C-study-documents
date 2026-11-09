#include <bits/stdc++.h>
using namespace std;
set<int>st;
int main(){
    int a,n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        st.insert(a);
    }
    cout<<st.size();
    cout<<'\n';
    for(auto &c:st)
        cout<<c<<' ';
}