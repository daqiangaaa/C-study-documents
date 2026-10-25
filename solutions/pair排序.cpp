// 输入 n 组 (x, y)，按 x 升序、x 相同时按 y 升序输出。
// 关键：pair 的比较天生就是「先比 first，相同再比 second」，
//       所以 sort(p, p + n) 后面什么都不用写。
//
// 四种排法（记这两条就够）：
//   sort(p, p + n)                               // x 升序，x 相同 y 升序
//   sort(p, p + n, greater<pair<int,int>>())     // x 降序，x 相同 y 降序
//   pair(-x,  y)  存进去 -> x 降序、x 相同 y 升序   // 「要降序就取负」
//   pair( x, -y)  存进去 -> x 升序、x 相同 y 降序
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    pair<int, int> p[1005];
    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;

    sort(p, p + n);            // 没有 cmp！

    for (int i = 0; i < n; i++)
        cout << p[i].first << ' ' << p[i].second << '\n';
    return 0;
}