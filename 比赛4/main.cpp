#include <bits/stdc++.h>
using namespace std;
const char *pat[10][5]
{
    {"XXX","X.X","X.X","X.X","XXX"},
    {"..X","..X","..X","..X","..X"},
    {"XXX","..X","XXX","X..","XXX"},
    {"XXX","..X","XXX","..X","XXX"},
    {"X.X","X.X","XXX","..X","..X"},
    {"XXX","X..","XXX","..X","XXX"},
    {"XXX","X..","XXX","X.X","XXX"},
    {"XXX","..X","..X","..X","..X"},
    {"XXX","X.X","XXX","X.X","XXX"},
    {"XXX","X.X","XXX","..X","XXX"},
};
int main()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%s",pat[s[j]-'0'][i]);
            if(j!=n-1)cout<<".";
            else cout<<"\n";
        }
    }
}
