#include <iostream>
using namespace std;
int mycmp(char x[],char y[])
{
    int i=0;
    while(x[i]!='\0'&&y[i]!='\0')
    {
        if(x[i]>y[i])return 1;
        if(x[i]<y[i])return -1;
        i++;
    }
    if(x[i]=='\0'&&y[i]=='\0')return 0;
    if(x[i]=='\0')return -1;
    return 1;
}
int main()
{
    char a[1005];
    char b[1005];
    cin>>a>>b;
    cout<<mycmp(a,b)<<'\n';
}