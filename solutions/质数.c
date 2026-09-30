#include <stdio.h>
int main()
{
    int a,i,isprime;
    int cnt=0;
    while(scanf("%d",&a)==1)
    {
        if(a<=0)
        {
            break;
        }
        cnt++;
        if(a==1||a==2)
        {
            printf("%d: no\n",cnt);
            continue;
        }
        isprime=1;
        for(i=2; i*i<=a; i++)
        {
            if(a%i==0)
            {
                isprime=0;
                break;
            }
        }
        if(isprime)
        {
            printf("%d: yes\n",cnt);
        }
        else
        {
            printf("%d: no\n",cnt);
        }
    }
    return 0;
}
