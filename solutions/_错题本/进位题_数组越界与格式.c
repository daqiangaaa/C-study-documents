#include <stdio.h>
int main(void)
{
    long long a,b;
    int i;
    int c=0;
    int d=0;
    while(scanf("%lld%lld",&a,&b)==2)
    {
        if (a==0&&b==0)
        {
            break;
        }
        for(i=1; i<=a; i=i*10)
        {
            c++;
        }
        for(i=1; i<=b; i=i*10)
        {
            d++;
        }
        int a[c]= {0};
        int b[d]= {0};
        long long f=a;
        long long g=b;
        for(i=0; i<c; i++)
        {
            a[i]=f%10;
            f=f/10;
        }
        for(i=0; i<d; i++)
        {
            b[i]=g%10;
            g=g/10;
        }
        int cishu;
        if(c>d)
        {
            cishu=c;
        }
        else
        {
            cishu=d;
        }
        int he[cishu];
        int zong=0;
        for(i=0; i<cishu; i++)
        {
            he[i]=a[i]+b[i];
            if(he[i]>=10)
            {
                zong++;
                he[i+1]= {1};
            }
            if(zong==0)
            {
                printf("No operation happened.");
            }
            else
            {
                printf("%d operation happened.",zong);
            }
        }
    }




    return 0;
}