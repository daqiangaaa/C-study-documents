#include <stdio.h>

int main(void)
{
    unsigned int n;
    scanf("%u", &n);
    printf("%u\n", (n >> 16) | (n << 16));
    return 0;
}
