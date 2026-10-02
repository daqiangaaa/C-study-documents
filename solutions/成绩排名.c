#include <stdio.h>
int main()
{
    int n,m,a[105],i,b,k;
    scanf("%d%d",&n,&m);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(k=0; k<m; k++)
    {
        int judge=1;
        scanf("%d",&b);
        for(i=0; i<n; i++)
        {
            if(a[b-1]>a[i])
            {
                judge++;
            }
        }
        printf("%d\n",judge);
    }
}
