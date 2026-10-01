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
            while(b<=c)
            {
                b=b+a;
                cnt++;
            }
            c=b;
        }
        printf("%lld\n",cnt);
    }
}