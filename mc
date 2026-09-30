#include <stdio.h>
int huoba[5][5]=
{
    {0,0,5,0,0},
    {0,5,10,5,0},
    {5,10,15,10,5},
    {0,5,10,5,0},
    {0,0,5,0,0},
};
int yingshi[5][5]=
{
    {10,10,10,10,10},
    {10,12,12,12,10},
    {10,12,15,12,10},
    {10,12,12,12,10},
    {10,10,10,10,10},
};
int main()
{
    int n,m,a,b,t;
    int tx[25],ty[25];
    int gx[25],gy[25];
    int i,k;
    scanf("%d%d%d%d%d",&n,&m,&a,&b,&t);
    for( i = 0; i<a; i++)
    {
        scanf("%d%d",&tx[i],&ty[i]);
    }
    for( i = 0; i<b; i++)
    {
        scanf("%d%d",&gx[i],&gy[i]);
    }
    int light,v;
    int ox,oy;
    int dx,dy;
    for( k =0; k<t; k++)
    {
        scanf("%d%d",&ox,&oy);
        light=0;
        for( i =0; i<a; i++)
        {
            dx=ox-tx[i];
            dy=oy-ty[i];
            if (dx<=2&&dx>=-2&&dy<=2&&dy>=-2)
            {
                v=huoba[dx+2][dy+2];
                if (v>light)
                {
                    light=v;
                }
            }
        }
        for( i =0; i<b; i++)
        {
            dx=ox-gx[i];
            dy=oy-gy[i];
            if (dx<=2&&dx>=-2&&dy<=2&&dy>=-2)
            {
                v=yingshi[dx+2][dy+2];
                if (v>light)
                {
                    light=v;
                }
            }
        }
        if(light>5)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
