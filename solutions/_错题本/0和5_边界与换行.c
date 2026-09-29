#include <stdio.h>
int main()
{
    int zero,five;
    while (scanf("%d%d\n",&zero,&five)!=EOF){
        if (five<9 &&zero!=0 &&five!=0){
            printf("-1\n");}
        if(five==0){
            printf("0\n");}
        if(zero==0&&five!=0){
            printf("-1\n");}
        if(zero !=0&&five%9==0){
        printf("");}
        if(zero!=0&&five%9!=0&&five>9){
            printf("");}
    }
}
