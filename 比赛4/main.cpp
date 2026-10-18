#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    double a[1005]= {0};
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,greater <double>());
    double sum=0.0;
    for(int i=1; i<n-1; i++)
    {
        sum+=a[i];
    }
    printf("%.2f",sum/(n-2));
}
