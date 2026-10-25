// 输入 n 个整数，按数值从小到大输出「数值 出现次数」。
// 关键：map 就是一个「桶号可以任意大」的桶数组 —— 对比桶计数：
//       桶计数要 a[i] <= 1e5 才能开数组，map 的键到 1e9 也无所谓。
//
// 两个最容易踩的坑：
//   1) mp[k] 不是查询，是「没有就当场建一个」！
//      只想问「有没有」要写 mp.count(k)（只动眼，不动手）。
//   2) map 没有「第 i 个」这种说法，所以不能 for (int i = 0; i < mp.size(); i++)。
//      而且那个写法里 mp[i] 会边取边插，size 一直变大 -> 死循环。
//      遍历一律用 for (auto &kv : mp)，循环里根本没有 i。
//
// map 天生按 key 升序（红黑树），所以不用排序，
// 但常数大：1e5 个不同的数实测 1.33 秒。只是统计频率时 sort + 扫描往往更快。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mp[a]++;               // 这里用 [] 是对的：本来就要「没有就建一个」
    }

    for (auto &kv : mp)        // kv.first = 数值，kv.second = 次数
        cout << kv.first << ' ' << kv.second << '\n';
    return 0;
}