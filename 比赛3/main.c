#include <stdio.h>
int main()
{
    double m,h,a;
    scanf("%lf%lf",&m,&h);
    a=(m/h)/h;
    if(a<18.5)
    {
        printf("Underweight\n");
    }
    else if(a<24)
    {
        printf("Normal\n");
    }
    else
    {
        printf("%g\nOverweight\n",a);
    }
}
