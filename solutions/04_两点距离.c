#include <stdio.h>
#include <math.h>
int main()
{
    double x1,y1,x2,y2,dx,dy,d;
    while(scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)!=EOF){
        dx=x1-x2;
        dy=y1-y2;
        d=sqrt(dx*dx +dy*dy);
        printf("%.2f\n",d);
    }
return 0;
}
