#include <bits/stdc++.h>
using namespace std;
int main()
{
    int p1,p2,p3;
    cin>>p1>>p2>>p3;
    string s;
    cin>>s;
    int n=(int)s.size();
    for(int i=0;i<n;i++){
        if(s[i]!='-'||i==0||i==n-1){cout<<s[i];continue;}
        char L=s[i-1];char R=s[i+1];
        bool same=((isdigit((unsigned char)L)&&isdigit((unsigned char)R))||(isalpha((unsigned char)L)&&(isalpha((unsigned char)R))));
        if(!same||R<=L){cout<<'-';continue;}
        if(R==L+1)continue;
        vector<char>mid;
        for(int c=L+1;c<R;c++)mid.push_back(c);
        if(p3==2)reverse(mid.begin(),mid.end());
        for(char c:mid)
            for(int t=0;t<p2;t++){
                if(p1==3) cout<<'*';
                else if(p1==2&&isalpha((unsigned char)c)) cout<<(char)toupper((unsigned char)c);
                else cout<<c;
            }
    }
    cout<<'\n';
    return 0;
}