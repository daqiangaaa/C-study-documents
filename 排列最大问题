#include <stdio.h>
int main(void)
{
    int t,n;
    int i,k;
    int a1,a2,a3;
    int b[6];
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d",&n);
        int carry=0;
        a1=n%10;
        a2=n/10%10;
        a3=n/100;
        b[0]=a1*100+a2*10+a3;
        b[1]=a1*100+a2+a3*10;
        b[2]=a1*10+a2*100+a3;
        b[3]=a1*10+a2+a3*100;
        b[4]=a1+a2*100+a3*10;
        b[5]=a1+a2*10+a3*100;
        for(k=0; k<6; k++)
        {
            if(b[k]<=750&&b[k]>=420)
            {
                carry=1;
            }
        }
        if(carry==1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
