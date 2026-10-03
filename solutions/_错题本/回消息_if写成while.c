#include <stdio.h>
int main()
{
    int T,n,k,i;
    scanf("%d",&T);
    while(T>0)
    {
        T--;
        int judge=0,ok=1;
        scanf("%d%d",&n,&k);
        char s[105];
        scanf("%s",s);
        for(i=0; i<n; i++)
        {
            while(s[i]=='a')
            {
                judge++;
            }
            if(judge>k)
            {
                ok=0;
                break;
            }
            if(s[i]=='b')
            {
                judge=0;
            }
        }
        if(ok==0)
        {
            printf("wuwuwu\n");
        }
        else
        {
            printf("she love me\n");
        }
    }
}