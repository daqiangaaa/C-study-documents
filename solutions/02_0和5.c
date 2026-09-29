#include <stdio.h>
int main()
{
    int zero,five,i,c;
    while (scanf("%d%d",&zero,&five)!=EOF){
      if(five<9&&zero>0){
        printf("0\n");}
        else if(zero==0){
            printf("-1\n");}
        else if (five>=9&&zero>0){
            c=five-five%9;
            for(i=0;i<c;i++){
                printf("5");}
            for(i=0;i<zero;i++){
                printf("0");}
    printf("\n");
      }
    }
    return 0;
}
