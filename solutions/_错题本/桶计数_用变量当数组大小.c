#include <stdio.h>
int main()
{
    int n,i,a;
    scanf("%d",&n);
    int cnt[n]={0};
    for(i=0;i<n;i++){
        scanf("%d",&a);
        cnt[a]++;
    }
    for(i=0;i<n;i++){
        printf("%d:%d",i,cnt[i]);
    }

}
