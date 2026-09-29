#include <stdio.h>
int main()
{
    int n,i,a;
    scanf("%d",&n);
    int cnt[10]={0};
    for(i=0;i<10;i++){
        scanf("%d",&a);
        cnt[a]++;
    }
    for(i=0;i<10;i++){
        printf("%d:%d",i,cnt[i]);
    }

}
