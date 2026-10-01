#include <stdio.h>
int main()
{
    int t,n,a,i,k,b;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        int c=0;
        long long cnt=0;
        scanf("%d%d",&n,&a);
        for(k=0; k<n; k++)
        {
            scanf("%d",&b);
            if(b<=c)
            {
                long long step=(c-b)/a+1;
                cnt=cnt+step;
                b=b+a*step;
            }
            c=b;
        }
        printf("%lld\n",cnt);
    }
}
