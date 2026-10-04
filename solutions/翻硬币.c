#include <stdio.h>
int main()
{
    char a[105];
    char b[105];
    int p[105];
    scanf("%s%s",a,b);
    int aa=0,bb=0,i,cnt=0,ans=0;
    for(i=0; a[i]!='\0'; i++)
    {
        if(a[i]=='*')aa++;
        if(b[i]=='*')bb++;
        if(a[i]!=b[i])
        {
            p[cnt]=i;
            cnt++;
        }
    }
    if(aa%2!=bb%2||cnt%2!=0)
    {
        printf("-1\n");
        return 0;
    }
    for(i=0; i<cnt; i+=2){ans=p[i+1]-p[i]+ans;}
    printf("%d\n",ans);
    return 0;
}
