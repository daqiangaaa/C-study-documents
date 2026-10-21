#include <stdio.h>
void minmax(int a[], int n, int *pmin, int *pmax) {
    *pmin=*pmax=a[0];
    for(int i=0;i<n;i++){
        if(a[i]<*pmin)*pmin=a[i];
        if(a[i]>*pmax)*pmax=a[i];
    }
}
int main() {
    int a[] = {5, 3, 9, 1, 7};
    int mn, mx;
    minmax(a, 5, &mn, &mx);
    printf("%d %d\n", mn, mx);   // ÆÚÍûÊä³ö 1 9
    return 0;
}
