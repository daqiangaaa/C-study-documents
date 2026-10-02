#include <stdio.h>

int main(void)
{
    static char a[1000005];
    if (scanf("%s", a) != 1) return 0;

    int i;
    int judge = 0;
    int cntk = 0, cntu = 0, cntn = 0;

    for (i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == 'K')
        {
            if (judge != 0 && judge != 1)
            {
                judge = -1;
                break;
            }
            judge = 1;
            cntk++;
        }
        else if (a[i] == 'U')
        {
            if (judge != 1 && judge != 2)
            {
                judge = -1;
                break;
            }
            judge = 2;
            cntu++;
        }
        else if (a[i] == 'N')
        {
            if (judge != 2 && judge != 3)
            {
                judge = -1;
                break;
            }
            judge = 3;
            cntn++;
        }
        else
        {
            judge = -1;
            break;
        }
    }
    if (judge == 3 && (cntn == cntk || cntn == cntu))
        judge = 4;

    printf(judge == 4 ? "YES\n" : "NO\n");
    return 0;
}
