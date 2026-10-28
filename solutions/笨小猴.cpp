/*
 * 笨小猴（洛谷 P1125，NOIP2008 提高组）
 * ────────────────────────────────────────────────────────────
 * 题意
 *   读一个单词，统计每个字母出现次数。
 *   令 mx = 出现最多的次数，mn = 出现最少的次数（只算出现过的字母），
 *   若 mx - mn 是质数 → 输出 "Lucky Word" 和这个差；
 *   否则                 → 输出 "No Answer" 和 0。
 *
 * 范围
 *   单词长度 <= 100，只有小写字母。
 *
 * 思路
 *   用 map<char,int> 当桶：键 = 字母，值 = 次数。
 *   好处是「只存出现过的字母」，所以求最小值时天然不会算到没出现的字母。
 *   然后遍历 map 求 mx / mn（map 只能遍历，没有 max()/min()）。
 *
 * 踩过的坑
 *   1) 我原来写 map<int> mp;  —— map 要两个模板参数 map<Key,Value>。
 *      少写一个，编译器就把 mp 当成 int，后面 6 条 error 全是这一条的连带。
 *   2) 我以为 map 有 .max() / .min()，其实没有。
 *      而且 map 是按 key 排序的，不是按 value 排序，
 *      所以 begin() 是字母最小的、rbegin() 是字母最大的，拿不到次数的极值，必须遍历。
 *   3) mn 的初值。我一开始想用 INT_MAX，更好的写法是 (int)s.size()
 *      —— 最小次数最多也就是整个字符串的长度，用不着 INT_MAX。
 *
 * 复杂度
 *   O(n log 26) = O(n)，n 是单词长度。
 * ────────────────────────────────────────────────────────────
 */
#include <bits/stdc++.h>
using namespace std;

bool isprime(int x)
{
    if (x < 2) return false;                 // 0 和 1 都不是质数
    for (int i = 2; i * i <= x; i++) {       // 用 i*i <= x，不用 sqrt
        if (x % i == 0) return false;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;

    map<char, int> mp;                       // 键是字母(char)，值是次数(int)
    for (int i = 0; i < (int)s.size(); i++) mp[s[i]]++;

    int mx = 0;
    int mn = (int)s.size();                  // 最小次数最多也就是串长
    for (auto &kv : mp) {
        mx = max(mx, kv.second);             // kv.first = 字母
        mn = min(mn, kv.second);             // kv.second = 次数
    }

    int d = mx - mn;
    if (isprime(d)) cout << "Lucky Word" << '\n' << d << '\n';
    else            cout << "No Answer" << '\n' << "0" << '\n';
    return 0;
}