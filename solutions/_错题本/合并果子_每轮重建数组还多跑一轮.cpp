#include <bits/stdc++.h>
using namespace std;
struct stu{ int sum; int id; };
bool cmp(const stu &x,const stu &y){
    if(x.sum!=y.sum)return x.sum<y.sum;
    return x.id<y.id;
}
int main(){
    int n; cin>>n;
    vector<stu>v(n);
    for(int i=0;i<n;i++){ cin>>v[i].sum; v[i].id=i; }
    sort(v.begin(),v.end(),cmp);
    v[1].sum=v[0].sum+v[1].sum;
    long long ans=v[0].sum+v[1].sum;
    for(int i=1;i<n;i++){
        vector<stu>v1(n-i);
        for(int j=0;j<n-i;j++) v1[j].sum=v[j+1].sum;
        sort(v1.begin(),v1.end(),cmp);
        v1[1].sum=v1[0].sum+v1[1].sum;
        ans+=v1[1].sum;
        for(int j=0;j<n-i;j++) v[j].sum=v1[j].sum;
    }
    cout<<ans<<'\n';
}