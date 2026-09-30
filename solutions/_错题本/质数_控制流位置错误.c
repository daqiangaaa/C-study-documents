#include <stdio.h>
int main()
{
    int a,b,i;
    int cnt=0;
    while(scanf("%d",&a)==1)
    {
        cnt++;
        if(a<=0)
        {
            break;
        }
        else if(a==1||a==2)
        {
            printf("%d:no\n",cnt);
            continue;
        }
        else
        {
            for(i=2; i*i<=a; i++)
            {
                if(a%i==0)
                {
                    printf("%d:yes\n",cnt);
                    continue;
                }
            }
            if(a%i!=0)
            {
                printf("%d:no\n",cnt);
            }
            return 0;
        }
    }
}