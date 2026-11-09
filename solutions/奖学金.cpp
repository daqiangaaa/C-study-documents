#include <bits/stdc++.h>
using namespace std;
struct stu{
    int yu;
    int shu;
    int ying;
    int id;
    int zong;
};
int cmp(const stu &a,const stu &b){
    if(a.zong!=b.zong)return a.zong>b.zong;
    if(a.yu!=b.yu)return a.yu>b.yu;
    return a.id<b.id;
}
int main(){
    int n;
    cin>>n;
    vector<stu>v(400);
    for(int i=0;i<n;i++){
        cin>>v[i].yu>>v[i].shu>>v[i].ying;
        v[i].zong=v[i].yu+v[i].shu+v[i].ying;
        v[i].id=i+1;
    }
    sort(v.begin(),v.begin()+n,cmp);
    for(int i=0;i<5;i++){
        cout<<v[i].id<<' '<<v[i].zong<<'\n';
    }
}