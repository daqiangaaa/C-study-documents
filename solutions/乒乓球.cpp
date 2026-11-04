#include <bits/stdc++.h>
using namespace std;
vector<char>v;
void run(const int need){
    int x=0,y=0;
    for(auto &c:v){
        if(c=='W')x++;
        if(c=='L')y++;
        if((x>=need||y>=need)&&abs(x-y)>=2){
            cout<<x<<":"<<y<<'\n';
            x=0;
            y=0;
        }
    }
    cout<<x<<":"<<y<<'\n';
}
int main(){
    char a;
    while(cin>>a&&a!='E'){
        v.push_back(a);
    }
    run(11);
    cout<<'\n';
    run(21);
}