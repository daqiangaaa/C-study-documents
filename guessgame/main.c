#include <stdio.h>>
#include <stdlib.h>>
#include <time.h>
int main(void)
{
    srand(time(0));
    int secret = rand()%100 + 1;
    int guess=0;
    int tries=0;
    while (guess != secret && tries< 7)
    {
        printf("请输入1~100之间的数");
        scanf("%d",&guess);
        tries++;
        if (guess > secret)
        {
            printf("大了\n") ;
        }
        else if(guess < secret)
        {
            printf("小了\n");
        }
        else
        {
            printf("猜对了\n");
            break;
        }
    }
    if (guess != secret)
    {
        printf("猜错了，正确答案是%d\n下次加油哦",secret);
    }
    return 0;
}
