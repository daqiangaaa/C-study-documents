#include <bits/stdc++.h>
using namespace std;
struct stu{
    int id;
    int score;
};
bool cmp(stu x,stu y){
    return x.score>y.score;
}
int main()
{
    int n;
    stu a[1005];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].id>>a[i].score;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        cout<<a[i].id<<" "<<a[i].score<<"\n";
    }
}
