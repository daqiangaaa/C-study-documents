#include <bits/stdc++.h>
using namespace std;
struct stu{
    int x;
    int y;
    int z;
};
bool cmp(stu &a,stu &b){
    return a.z<b.z;
}
int main(){
    double ans=0.0;
    int n;
    cin>>n;
    vector<stu>v(50005);
    for(int i=0;i<n;i++){
        cin>>v[i].x>>v[i].y>>v[i].z;
    }
    sort(v.begin(),v.begin()+n,cmp);
    for(int i=0;i<n-1;i++){
        ans+=sqrt(pow(v[i+1].x-v[i].x,2)+pow(v[i+1].y-v[i].y,2)+pow(v[i+1].z-v[i].z,2));
    }
    cout<<fixed<<setprecision(3)<<ans<<'\n';
}