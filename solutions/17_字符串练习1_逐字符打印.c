#include <stdio.h>

int main(void)
{
    char a[1005];
    int i = 0;

    scanf("%s", a);

    while (a[i] != '\0')
    {
        printf("%c", a[i]);      /* ← 改这里 */
        i++;
    }
    printf("\n");                /* 别忘了行尾换行 */

    return 0;
}