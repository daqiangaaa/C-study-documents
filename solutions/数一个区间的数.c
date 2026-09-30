#include <stdio.h>
int main()
{
    int L,R,a,i,k;
    int cnt=0;
    scanf("%d%d",&L,&R);
    for(i=L; i<=R; i++)
    {
        k=i;
        while(k>0)
        {
            a=k%10;
            if(a==3)
            {
                cnt++;
            }
            k/=10;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
