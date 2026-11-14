#include <bits/stdc++.h>
using namespace std;
struct stu{
    string name;
    int year;
    int mu;
    int day;
    int id;
};
bool cmp(stu &x,stu &y){
    if(x.year!=y.year)return x.year<y.year;
    else if(x.mu!=y.mu)return x.mu<y.mu;
    else if(x.day!=y.day)return x.day<y.day;
    return x.id>y.id;
}
int main(){
    int n;
    cin>>n;
    vector<stu>v(105);
    for(int i=0;i<n;i++){
        cin>>v[i].name>>v[i].year>>v[i].mu>>v[i].day;
        v[i].id=i+1;
    }
    sort(v.begin(),v.begin()+n,cmp);
    for(int i=0;i<n;i++){
        if(i)cout<<'\n'<<v[i].name;
        else cout<<v[i].name;
    }
}