#include <stdio.h>

int main(void)
{
    long long n;
    while (scanf("%lld", &n) == 1)
    {
        long long ans = n / 6 * 2 + (n % 6 >= 2 ? 1 : 0);
        printf("%lld\n", ans);
    }
    return 0;
}
