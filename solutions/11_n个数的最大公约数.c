#include <stdio.h>
int main(void)
{
    int n;
    long long a;
    int i;
    long long c[1005]={0};
    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++){
            scanf("%lld",&c[i]);
        }
        for(i=1;i<n;i++){
            while(c[i]!=0){
                a=c[0]%c[i];
                c[0]=c[i];
                c[i]=a;
            }
        }
        printf("%lld\n",c[0]);
    }
    return 0;
}
