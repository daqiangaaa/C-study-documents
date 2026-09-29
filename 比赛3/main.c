#include <stdio.h>
int main()
{
    int a,b,c,d,e;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    a=a*60;
    c=c*60;
    e=c+d-a-b;
    printf("%d %d",e/60,e%60);
    return 0;
}
