#include <stdio.h>
int main()
{
    int a[5];
    int i;
    int sum,mx,mn;
    for(i = 0; i<5; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i = 0; i<5; i++)
    {
        sum +=a[i];
    }
    printf("总和=%d\n",sum);
    mx=a[0];
    mn=a[0];
    for(i = 0; i<5; i++)
    {
        if(mx<a[i])
        {
            mx=a[i];
        }
    }
    printf("最大值=%d\n",mx);
    for(i = 0; i<5; i++)
    {
        if(mn>a[i])
        {
            mn=a[i];
        }
    }
    printf("最小值=%d\n",mn);
}
