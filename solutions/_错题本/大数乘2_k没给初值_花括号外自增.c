#include <stdio.h>
int main(void)
{
    char a[105];
    char r[110];
    int i,k,d;
    while(scanf("%s",a)==1)
    {
        int len=0,carry=0;
        for(i=0; a[i]!='\0'; i++)
        {
            len++;
        }
        for(i=len-1; i>=0; i--)
        {
            d=(a[i]-'0')*2+carry;
            r[k]=d%10;
            carry=d/10;
            k++;
        }
        if(carry>0)r[k]=carry;
        k++;
        for(i=k-1; i>=0; i--)printf("%d",r[i]);
        printf("\n");
    }
}