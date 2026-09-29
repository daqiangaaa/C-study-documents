#include <stdio.h>
int main(void)
{
    int i=0;
    int cnt;
    char s[1005];
    scanf("%s",s);
    while(s[i]!='\0'){
        if(s[i]=='n'){cnt++;}
        i++;
    }
    printf("%d",cnt);
    return 0;
}
