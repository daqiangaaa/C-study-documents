#include <stdio.h>

int main(void)
{
    long long a, b;
    long long ta, tb;                    /* 用来拆分的副本 */
    int da[25], db[25];                  /* 存各位数字：a 的个位放 da[0] */
    int i, c, d, maxlen;
    int carry, count;

    while (scanf("%lld%lld", &a, &b) == 2)
    {
        if (a == 0 && b == 0)
        {
            break;
        }

        /* ===== 1. 把 a 拆成一位一位，存进数组 ===== */
        c = 0;                           /* ★ 每一组都要重新清零 */
        ta = a;
        while (ta > 0)                   /* ★ 拆的同时数位数，一趟搞定 */
        {
            da[c] = ta % 10;             /* 取出个位，存进数组 */
            ta = ta / 10;                /* 扔掉个位 */
            c++;                         /* 位数 +1 */
        }

        d = 0;
        tb = b;
        while (tb > 0)
        {
            db[d] = tb % 10;
            tb = tb / 10;
            d++;
        }

        /* ===== 2. 逐位相加，统计进位 ===== */
        maxlen = (c > d) ? c : d;        /* 取位数多的那个 */
        carry = 0;
        count = 0;

        for (i = 0; i < maxlen; i++)
        {
            /* ★ 位数不够的那一位，当成 0 —— 这就是你说的"位数不一样"的处理 */
            int x = (i < c) ? da[i] : 0;
            int y = (i < d) ? db[i] : 0;

            if (x + y + carry >= 10)     /* ★ 别忘了加上上一位的进位 */
            {
                carry = 1;
                count++;
            }
            else
            {
                carry = 0;               /* ★ 不进位也要更新 carry */
            }
        }

        /* ===== 3. 输出（在循环外面，一组只输出一次）===== */
        if (count == 0)
        {
            printf("No operation happened.\n");
        }
        else if (count == 1)
        {
            printf("1 operation happened.\n");
        }
        else
        {
            printf("%d operations happened.\n", count);
        }
    }

    return 0;
}
