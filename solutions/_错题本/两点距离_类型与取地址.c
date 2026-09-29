#include <stdio.h>
#include <math.h>
int main()
{
    int x1,y1,x2,y2,dx,dy,d;
    while(scanf("%1f%1f%1f%1f",&x1,%y1,&x2,&y1)!=EOF){
        dx=x1-x2;
        dy=y1-y2;
        if(dx<0){
            dx=-dx;
        }
        if(dy=0){
            dy=-dy;
        }
        d=sqrt(dx*dx +dy*dy);
        printf("%.2f\n",d);
    }
return 0;
}
