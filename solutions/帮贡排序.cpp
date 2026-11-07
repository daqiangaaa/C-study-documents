#include <bits/stdc++.h>
using namespace std;
struct person{
    string name;
    string posi;
    int contri;
    int grade;
    int id;
};
int former(string s){
    int ok=0;
    if(s=="BangZhu")ok=1;
    if(s=="FuBangZhu")ok=2;
    if(s=="HuFa")ok=3;
    if(s=="ZhangLao")ok=4;
    if(s=="TangZhu")ok=5;
    if(s=="JingYing")ok=6;
    if(s=="BangZhong")ok=7;
    return ok;
}
bool isleader(const person &s){
    if(s.posi=="BangZhu"||s.posi=="FuBangZhu")return true;
    return false;
}
bool cmp1(const person &a,const person &b){
    if(isleader(a)!=isleader(b))return isleader(a);
    if(a.contri!=b.contri)return a.contri>b.contri;
    return a.id<b.id;
}
bool cmp2(const person &a,const person &b){
    if(former(a.posi)!=former(b.posi))return former(a.posi)<former(b.posi);
    if(a.grade!=b.grade)return a.grade>b.grade;
    return a.id<b.id;
}
int main(){
    int n;
    cin>>n;
    vector<person>v(200);
    for(int i=0;i<n;i++){
        cin>>v[i].name>>v[i].posi>>v[i].contri>>v[i].grade;
        v[i].id=i;
    }
    sort(v.begin(),v.begin()+n,cmp1);
    for(int i=3;i<n;i++){
        if(i<5)v[i].posi="HuFa";
        else if(i>=5&&i<9)v[i].posi="ZhangLao";
        else if(i>=9&&i<16)v[i].posi="TangZhu";
        else if(i>=16&&i<41)v[i].posi="JingYing";
        else v[i].posi="BangZhong";
    }
    sort(v.begin(),v.begin()+n,cmp2);
    for(int i=0;i<n;i++){
        cout<<v[i].name<<' '<<v[i].posi<<' '<<v[i].grade<<'\n';
    }
}