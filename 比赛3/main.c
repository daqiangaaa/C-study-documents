#include <stdio.h>
int main()
{
    char a[105];
    scanf("%s",a);
    int last,i,b;
    for(last=0;a[last]!='\0';last++){}
    for(last;last>0;last=last-1){
            b=last;
        for(i=0;i<b;i++){
            printf("%c",a[i]);
        }
    printf("\n");
    }
}
