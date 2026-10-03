#include <stdio.h>
int main()
{
    int t,i;
    long long a,b,c;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        if(a%3==b%3||a%3==c%3||b%3==c%3)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}
