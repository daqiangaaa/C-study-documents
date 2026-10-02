#include <stdio.h>
int main()
{
    char a[100005];
    scanf("%s",a);
    int judge=0;
    int i;
    int cntk=0;
    int cntu=0;
    int cntn=0;
    for(i=0; i<100005; i++)
    {
        while(a[i]!='\0')
        {
            while(a[i]=='K')
            {
                cntk++;
            }
            while(a[i]=='U')
            {
                cntu++;
            }
            while(a[i]=='N')
            {
                cntn++;
            }
            if(a[i]=='K')
            {
                judge=1;
            }
            if(judge==1&&a[i]=='U')
            {
                judge=2;
            }
            if(judge==2&&a[i]=='N')
            {
                judge=3;
            }
            if(judge==3&&cntk==cntn)
            {
                judge=4;
            }
            if(judge==3&&cntu==cntn)
            {
                judge=4;
            }
        }
        if(a[i]=='\0')
        {
            break;
        }
    }
    if(judge==4)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}
