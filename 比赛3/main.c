#include <stdio.h>
int main()
{
    int n;
    int judge=0;
    scanf("%d",&n);
    if(n%100==0)
    {
        if(n%400==0)
        {
            judge=1;
        }
    }
    else
    {
        if(n%4==0)
        {
            judge=1;
        }
    }
    printf("%d",judge==1);
}
