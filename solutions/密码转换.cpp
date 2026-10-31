#include <bits/stdc++.h>
using namespace std;
int judge(string x){
    int ok=-1;
    if(x=="zero")ok=0;
    if(x=="one"||x=="a"||x=="another"||x=="first")ok=1;
    if(x=="two"||x=="both"||x=="second")ok=2;
    if(x=="three"||x=="third")ok=3;
    if(x=="four")ok=4;
    if(x=="five")ok=5;
    if(x=="six")ok=6;
    if(x=="seven")ok=7;
    if(x=="eight")ok=8;
    if(x=="nine")ok=9;
    if(x=="ten")ok=10;
    if(x=="eleven")ok=11;
    if(x=="twelve")ok=12;
    if(x=="thirteen")ok=13;
    if(x=="fourteen")ok=14;
    if(x=="fifteen")ok=15;
    if(x=="sixteen")ok=16;
    if(x=="seventeen")ok=17;
    if(x=="eighteen")ok=18;
    if(x=="nineteen")ok=19;
    if(x=="twenty")ok=20;
    return ok;
}
int main(){
    string line,s;
    int a[10],cnt=0;
    getline(cin,line);
    for(auto &c:line){if(c>='A'&&c<='Z')c=c+'a'-'A';}
    for(int i=0;i<(int)line.size();){
        if(line[i]==' '){++i;continue;}
        int j=i;
        while(line[j]!=' '&&j<(int)line.size())j++;
        s=line.substr(i,j-i);
        if(judge(s)!=-1){
            a[cnt]=judge(s);
            cnt++;
        }
        i=j;
    }
    for(int i=0;i<cnt;i++){
        a[i]=(a[i]*a[i])%100;
    }
    sort(a,a+cnt);
    string t;
    for(int i=0;i<cnt;i++){
        t+=char('0'+a[i]/10);
        t+=char('0'+a[i]%10);
    }
    int k=0;
    while(k<(int)t.size()&&t[k]=='0')k++;
    if(k==(int)t.size())cout<<0;
    else cout<<t.substr(k);
}
