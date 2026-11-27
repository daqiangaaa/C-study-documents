#include <bits/stdc++.h>
using namespace std;
struct stu{
    int t;
    int id;
};
bool cmp(const stu &x,const stu &y){
    if(x.t!=y.t)return x.t<y.t;
    return x.id<y.id;
}
int main(){
    int n;
    double ans=0.0;
    cin>>n;
    vector<stu>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].t;
        v[i].id=i;
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<n;i++){
        cout<<v[i].id+1<<' ';
        for(int j=i+1;j<n;j++)
            ans+=v[i].t;
    }
    cout<<'\n';
    cout<<fixed<<setprecision(2)<<(double)ans/n<<'\n';
}