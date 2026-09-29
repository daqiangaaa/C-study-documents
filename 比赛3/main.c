#include <stdio.h>
int main()
{
    int s,v,t;
    scanf("%d%d",&s,&v);
    t=s/v;
    if(s%v!=0){t=t+1;}
    t=t+10;
    t=480-t;
    while(t<0){t=t+1440;}
    printf("%02d:%02d\n",t/60,t%60);
    return 0;
}
