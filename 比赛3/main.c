#include <stdio.h>

int main()
{
    int L, R, i, j;
    int cnt = 0;
    char s[20];

    scanf("%d%d", &L, &R);

    for (i = L; i <= R; i++)
    {
        sprintf(s, "%d", i);          /* 数字 -> 字符串 */
        for (j = 0; s[j] != '\0'; j++) /* 遍历每个字符，到 '\0' 停 */
        {
            if (s[j] == '3')
            {
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);
    return 0;
}
