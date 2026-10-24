#include <bits/stdc++.h>
using namespace std;

int a[105];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n);

    /* 外层走「被数的对象」：一个数只加一次 */
    int cnt = 0;
    for (int k = 0; k < n; k++) {
        bool ok = false;
        for (int i = 0; i < n && !ok; i++)
            for (int j = i + 1; j < n; j++)
                if (a[i] + a[j] == a[k]) { ok = true; break; }
        if (ok) cnt++;              /* 找到第一种凑法就够了，不再数第二种 */
    }

    cout << cnt << "\n";
    return 0;
}