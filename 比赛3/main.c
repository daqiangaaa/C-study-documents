#include <stdio.h>
int main()
{
    long long a;
    while(scanf("%lld",&a)!=EOF)
    {
        if(a>2&&a%3==0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
