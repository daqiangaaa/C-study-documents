#include <stdio.h>

int huoba[5][5] = {
    {0,  0,  5,  0,  0},
    {0,  5, 10,  5,  0},
    {5, 10, 15, 10,  5},
    {0,  5, 10,  5,  0},
    {0,  0,  5,  0,  0}
};

int yingshi[5][5] = {
    {10, 10, 10, 10, 10},
    {10, 12, 12, 12, 10},
    {10, 12, 15, 12, 10},
    {10, 12, 12, 12, 10},
    {10, 10, 10, 10, 10}
};

int main()
{
    int n,m,a,b,t;
    int tx[25],ty[25];
    int gx[25],gy[25];
    int i,k;                    /* ★ 两个循环变量 */
    int light,v;
    int ox,oy;
    int dx,dy;

    scanf("%d%d%d%d%d",&n,&m,&a,&b,&t);

    for(i=0;i<a;i++)
    {
        scanf("%d%d",&tx[i],&ty[i]);
    }
    for(i=0;i<b;i++)
    {
        scanf("%d%d",&gx[i],&gy[i]);
    }

    for(k=0;k<t;k++)            /* ★ 外层用 k */
    {
        scanf("%d%d",&ox,&oy);  /* ★ 边读边算 */

        light=0;

        for(i=0;i<a;i++)        /* 内层用 i，不再冲突 */
        {
            dx=ox-tx[i];
            dy=oy-ty[i];
            if (dx>=-2&&dx<=2&&dy>=-2&&dy<=2)
            {
                v=huoba[dx+2][dy+2];
                if (v>light) light=v;
            }
        }

        for(i=0;i<b;i++)
        {
            dx=ox-gx[i];
            dy=oy-gy[i];
            if (dx>=-2&&dx<=2&&dy>=-2&&dy<=2)
            {
                v=yingshi[dx+2][dy+2];
                if (v>light) light=v;
            }
        }

        if (light>5) printf("Yes\n");
        else         printf("No\n");
    }

    return 0;
}
