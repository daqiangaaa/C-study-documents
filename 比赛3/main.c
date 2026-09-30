#include <stdio.h>
int main()
{
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int n;
    scanf("%d",&n);
    if(n%2==0)
    {
        b=1;
        if(n>4&&n<=12)
        {
            a=1;
        }
        else
        {
            c=1;
        }
    }
    else if(n>4&&n<=12)
    {
        b=1;
        if(n%2==0)
        {
            a=1;
        }
        else
        {
            c=1;
        }
    }
    else
    {
        d=1;
    }
    printf("%d %d %d %d",a,b,c,d);
}
