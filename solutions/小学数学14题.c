#include <stdio.h>
#include <math.h>
int main()
{
    int t;
    scanf("%d",&t);
    if(t==1){printf("I love Luogu!\n");}
    if(t==2){printf("6 4\n");}
    if(t==3){printf("3\n12\n2\n");}
    if(t==4){printf("%g\n",500.0/3);}
    if(t==5){printf("%d\n",480/32);}
    if(t==6){printf("%g\n",sqrt(117));}
    if(t==7){printf("110\n90\n0\n");}
    if(t==8){printf("%g\n%g\n%g\n",2*3.141593*5,3.141593*5*5,4.0/3*3.141593*125);}
    if(t==9){printf("22\n");}
    if(t==10){printf("9\n");}
    if(t==11){printf("%g\n",100.0/3);}
    if(t==12){printf("%d\n%c\n",'M'-'A'+1,'A'+17);}
    if(t==13){printf("%d\n",(int)pow(4.0/3*3.141593*(64+1000), 1.0/3.0));}
    if(t==14){printf("50\n");}
    return 0;
}

