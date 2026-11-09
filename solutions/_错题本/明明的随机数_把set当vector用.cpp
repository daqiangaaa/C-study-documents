#include <bits/stdc++.h>
using namespace std;
set<int>st;
int main(){
    int a,n;
    for(int i=0;i<n;i++){
        cin>>a;
        st.push_back(a);
    }
    cout<<st.size();
    for(int i=0;i<n;i++){
        if(i)cout<<' '<<st[i];
        else st[i];
    }
}