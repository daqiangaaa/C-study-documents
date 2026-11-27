#include <bits/stdc++.h>
using namespace std;
struct gold{
    int m;
    double v;
    double p;
};
bool cmp(const gold &x,const gold &y){
    if(x.p!=y.p)return x.p>y.p;
    return x.m>y.m;
}
int main(){
    int N,T;
    cin>>N>>T;
    vector<gold>ve(N);
    for(int i=0;i<N;i++){
        cin>>ve[i].m>>ve[i].v;
        ve[i].p=(double)ve[i].v/ve[i].m;
    }
    sort(ve.begin(),ve.end(),cmp);
    double ans=0.0;
    for(int i=0;i<N;i++){
        if(T>=ve[i].m){
            T-=ve[i].m;
            ans+=ve[i].v;
        }
        else {
            ans+=(double)ve[i].p*T;
            break;
        }
    }
    cout<<fixed<<setprecision(2)<<ans<<'\n';
}