#include <bits/stdc++.h>
using namespace std;
struct game{
    int start;
    int end;
};
bool cmp(const game &x,const game &y){
    return x.end<y.end;
}
int main(){
    int n;
    cin>>n;
    vector<game>v(n);
    int last=-1;
    for(int i=0;i<n;i++){
        cin>>v[i].start>>v[i].end;
    }
    sort(v.begin(),v.end(),cmp);
    long long ans=0;
    for(int i=0;i<n;i++){
        if(v[i].start>=last){
            ans++;
            last=v[i].end;
        }
    }
    cout<<ans<<'\n';
}