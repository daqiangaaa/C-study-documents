#include <stdio.h>
int main(void)
{
    char s[1005];
    int i=0;
    int cnt=-3;
    scanf("%s",s);
    while(s[i]!='\0')
    {
        if(s[i]=='n')
        {
            cnt++;
        }
        i++;
    }
    printf("%d",cnt);
    return 0;
}
