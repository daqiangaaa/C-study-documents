#include <stdio.h>
int gcd(int x,int y)
{
    int q;
    while(y!=0)
    {
        q=x%y;
        x=y;
        y=q;
    }
    return x;
}
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)==3)
    {
        if(a==2&&gcd(b,c)==1)printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
