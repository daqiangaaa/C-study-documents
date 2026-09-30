#include  <stdio.h>
int gcd(int x,int y)
{
    while(y!=0)
    {
        int s=x%y;
        x=y;
        y=s;
    }
    return x;
}
int main()
{
    int a,b,n,t,i,f,sum,den;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d%d",&a,&b);
        sum=2*a*b;
        if(sum==0)
        {
            printf("0\n");
            continue;
        }
        n=a+b;
        den=n*(n-1);
        f=gcd(sum,den);
        if(den/f==1)
        {
            printf("%d\n",sum/f);
        }
        else
        {
            printf("%d/%d\n",sum/f,den/f);
        }
    }
    return 0;
}
