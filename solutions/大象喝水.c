#include <stdio.h>
int main()
{
    int r,h,sum,v;
    scanf("%d%d",&h,&r);
    v=314*r*r*h;
    sum=2000000/v;
    if(2000000%v!=0)
    {
        sum++;
    }
    printf("%d\n",sum);
    return 0;
}
