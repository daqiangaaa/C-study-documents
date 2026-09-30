#include <stdio.h>

int main()
{
    long long a, b, k;

    while (scanf("%lld%lld", &a, &b) == 2)
    {
        k = (a + b) / 3;
        if (a < k) k = a;
        if (b < k) k = b;
        printf("%lld\n", k);
    }

    return 0;
}
