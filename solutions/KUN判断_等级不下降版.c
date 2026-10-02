#include <stdio.h>

/* K=0  U=1  N=2, 其余字符返回 -1 */
int grade(char c)
{
    if (c == 'K') return 0;
    if (c == 'U') return 1;
    if (c == 'N') return 2;
    return -1;
}

int main(void)
{
    static char a[1000005];
    if (scanf("%s", a) != 1) return 0;

    int i;
    int cntk = 0, cntu = 0, cntn = 0;
    int prev = -1, ok = 1;

    for (i = 0; a[i] != '\0'; i++)
    {
        int g = grade(a[i]);
        if (g < 0 || g < prev) { ok = 0; break; }   /* 怪字符 或 等级掉回去了 */
        prev = g;
        if (g == 0) cntk++;
        else if (g == 1) cntu++;
        else cntn++;
    }

    if (ok && cntk > 0 && cntu > 0 && cntn > 0 && (cntn == cntk || cntn == cntu))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
