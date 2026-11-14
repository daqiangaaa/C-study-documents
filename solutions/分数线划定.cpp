#include <bits/stdc++.h>
using namespace std;
struct stu{
    int id;
    int grade;
};
bool cmp(stu &x,stu &y){
    if(x.grade!=y.grade)return x.grade>y.grade;
    return x.id<y.id;
}
int main(){
    int n,k;
    cin>>n>>k;
    k=k*15/10;
    vector<stu>v(5005);
    for(int i=0;i<n;i++){
        cin>>v[i].id>>v[i].grade;
    }
    sort(v.begin(),v.begin()+n,cmp);
    int cnt=0;
    for(int i=0;i<k||v[i-1].grade==v[i].grade;i++){
        cnt++;
    }
    cout<<v[k-1].grade<<' '<<cnt;
    for(int i=0;i<k||v[i-1].grade==v[i].grade;i++){
        cout<<'\n'<<v[i].id<<' '<<v[i].grade;
    }
}