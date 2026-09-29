#include <stdio.h>
int main()
{
    int tou,tui,T,i,tu,ji;
    while(scanf("%d",&T)>0){
        for(i=0;i<T;i++){
            scanf("%d%d",&tou,&tui);
            tu=tui-tou*2;
            ji=tou-tu;
            printf("\n");
            printf("%d%d",ji,tu);
        }
    }
    return 0;
}
