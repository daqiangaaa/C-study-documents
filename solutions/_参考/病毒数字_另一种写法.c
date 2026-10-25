#include <stdio.h>

int main()
{
    int m[10] = {5, 9, 8, 7, 6, 0, 4, 3, 2, 1};
    int i;

    for (i = 0; i <= 100; i++)
    {
        if (i != 0)
        {
            printf(" ");
        }

        if (i < 10)                                   /* 一位数 */
        {
            printf("%d", m[i]);
        }
        else if (i < 100)                             /* 两位数 */
        {
            printf("%d%d", m[i / 10], m[i % 10]);
        }
        else                                          /* 100 */
        {
            printf("%d%d%d", m[i / 100], m[i / 10 % 10], m[i % 10]);
        }
    }

    printf("\n");
    return 0;
}
