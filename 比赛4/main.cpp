#include <bits/stdc++.h>
using namespace std;

int a[] = {3, 9, 4, 7, 1};
int n = 5;

int main()
{
    int mx = 0, mn = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > mx) mx = a[i];
        if (a[i] < mn) mn = a[i];
    }
    cout << mx << " " << mn << "\n";
    return 0;
}
