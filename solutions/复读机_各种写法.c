#include <stdio.h>
#include <string.h>

/* ---------------------------------------------------------------------
   复读机：输入一个只含字母的串（长度 <= 100）。把它、去掉最后一个字符的它、
   再去掉一个的它……一直打印到只剩一个字符，每行一个。

   这个文件把同一件事的 5 种写法放在一起，方便对照。
   运行：先输入编号 1~5，再输入字符串（用空格隔开）。
       1 abcd  ->  自己数长度 + 逐字符打印
       2 abcd  ->  改结尾的 '\0' 截短 + puts
       3 abcd  ->  %.*s 精度控制（不动原串）
       4 abcd  ->  指针版（一个长度变量都不用）
       5 abcd  ->  递归
   5 种写法在 abcd / a / Z / abcdefghij 上输出完全一致。
   --------------------------------------------------------------------- */

/* ① 自己数长度；外层管长度、内层管打印 */
void way1(const char *a)
{
    int n, i;
    for (n = 0; a[n] != '\0'; n++) {}       /* 相当于自己写了一遍 strlen */
    for (; n > 0; n--)
    {
        for (i = 0; i < n; i++) putchar(a[i]);
        putchar('\n');
    }
}

/* ② 把最后一个字符改成 '\0'，字符串就"变短"了 —— C 字符串靠 '\0' 定长 */
void way2(char *a)
{
    int n = (int)strlen(a);
    while (n > 0)
    {
        puts(a);                /* puts = 打印字符串 + 自动换行 */
        a[--n] = '\0';
    }
}

/* ③ %.*s：那个 * 表示"精度由参数给"，即最多打印 n 个字符；原串一位都不动 */
void way3(const char *a)
{
    int n = (int)strlen(a);
    while (n > 0)
    {
        printf("%.*s\n", n, a);
        n--;
    }
}

/* ④ 用指针记住"结尾在哪"，往回退一格就等于砍掉最后一个字符 */
void way4(char *a)
{
    char *p = a;
    while (*p) p++;                 /* p 一路挪到结尾的 '\0' 上 */
    while (p != a)
    {
        puts(a);
        p--;
        *p = '\0';
    }
}

/* ⑤ 先打印完整的自己，再把自己截短一格，然后让"短一个字符的自己"重复 —— 递归 */
void way5(char *s)
{
    if (*s == '\0') return;         /* 空串：什么都不打印 */
    puts(s);
    s[strlen(s) - 1] = '\0';
    way5(s);
}

int main(void)
{
    char a[105], buf[105];
    int which;

    if (scanf("%d", &which) != 1) return 0;
    if (scanf("%s", a) != 1) return 0;

    if (which == 1) way1(a);
    else if (which == 2) { strcpy(buf, a); way2(buf); }   /* 2/4/5 会改原串，先复制一份 */
    else if (which == 3) way3(a);
    else if (which == 4) { strcpy(buf, a); way4(buf); }
    else if (which == 5) { strcpy(buf, a); way5(buf); }

    return 0;
}
