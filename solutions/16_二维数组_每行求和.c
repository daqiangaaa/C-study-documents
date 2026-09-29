#include <stdio.h>
int main()
{
    int g[3][4];
    int i,j;
    int sum;
    for(i=0; i<3; i++)
    {
        sum=0;
        for(j=0; j<4; j++)
        {
            scanf("%d",&g[i][j]);
            sum+=g[i][j];
        }
        printf("%d\n",sum);
    }
    return 0;
}
