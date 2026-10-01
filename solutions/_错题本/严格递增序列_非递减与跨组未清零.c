#include <stdio.h>
int main()
{
    int t,n,a,i,k,b;
    int c=0;
    int cnt=0;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d%d",&n,&a);
        for(k=0; k<n; k++)
        {
            scanf("%d",&b);
            if(n==1)
            {
                printf("0\n");
                continue;
            }
            while(b<c)
            {
                b=b+a;
                cnt++;
            }
            c=b;
        }
        printf("%d\n",cnt);
    }
}