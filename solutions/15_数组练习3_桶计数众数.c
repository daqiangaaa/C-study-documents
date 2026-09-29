#include <stdio.h>
int main()
{
    int n,i,a;
    scanf("%d",&n);
    int cnt[10]= {0};
    for(i=0; i<n; i++)
    {
        scanf("%d",&a);
        cnt[a]++;
    }
    for(i=0; i<10; i++)
    {
        printf("%d:%d\n",i,cnt[i]);
    }
    int best_i=0;
    for(i=0; i<10; i++)
    {
        if(cnt[best_i]<cnt[i])
        {
            best_i=i;
        }
    }
    printf("最多的是:%d\n",best_i);
    return 0;
}
