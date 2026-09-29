#include <stdio.h>
int main()
{
    int m[10]= {5,9,8,7,6,0,4,3,2,1};
    int i;
    for (i=0; i<=100; i++)
    {
        if(i!=0)
        {
            printf(" ");
        }
        if (i<10)
        {
            printf("%d",m[i]);
        }
        else if(i<100)
        {
            printf("%d%d",m[i/10],m[i%10]);
        }
        else
        {
            printf("955");
        }
    }
    printf("\n");
    return 0 ;
}
