#include <bits/stdc++.h>
using namespace std;
struct person{
    string name;
    int posi;
    int contri;
    int grade;
    int id;
};
int former(string s){ return 0; }
bool cmp1(const person &a,const person &b){
    if(a.posi==1||a.posi==2)return false;
    if(a.contri!=b.contri)return a.contri>b.contri;
    return a.id<b.id;
}