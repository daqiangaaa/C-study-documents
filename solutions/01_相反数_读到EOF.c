#include <stdio.h>

int main(void)
{
    int n;

    /* scanf 返回成功读入的变量个数，读到文件结尾返回 EOF。
       每成功读到一个 n，就输出 -n，然后继续读下一个。 */
    while (scanf("%d", &n) != EOF)
    {
        printf("%d\n", -n);
    }

    return 0;
}
