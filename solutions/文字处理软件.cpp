/*
 * 文字处理软件（洛谷 P5734，【深基6.例6】）
 * ────────────────────────────────────────────────────────────
 * 题意
 *   给一个初始字符串，然后 q 次操作，每次操作后输出当前字符串：
 *     1 后接 t   → 把 t 接到末尾
 *     2 a b      → 只保留从第 a 个字符起、共 b 个字符
 *     3 a t      → 在第 a 个字符前面插入 t
 *     4 t        → 查找 t 第一次出现的起始位置（从 0 开始），找不到输出 -1
 *
 * 思路
 *   这题真正想教的是：这四个操作 std::string 全都有现成的成员函数。
 *     1 → s += t
 *     2 → s = s.substr(a, b)
 *     3 → s.insert(a, t)
 *     4 → s.find(t)，找不到返回 string::npos
 *
 * 踩过的坑（我原来四个都手写了循环，三个边界全错）
 *   1) 第 2 个操作里 b 是「取几个」，不是「到第几个」。
 *      我写 for (i = a; i <= b; i++)，把 b 当成终点下标，只取了 1 个字符。
 *   2) 第 3 个操作我写成「先放 s1[i]，再放 s2」—— 那是在 s1[a] 后面插，
 *      题目要的是在它前面插。而且 i 只走到 size-1，
 *      所以 a == size（插到末尾）时永远插不进去。
 *   3) 第 4 个操作 return i-cnt 差了一位（i 是最后一个匹配字符的下标），
 *      更严重的是循环末尾没有 return —— 函数返回栈垃圾。
 *      编译器其实警告了：warning: control reaches end of non-void function [-Wreturn-type]
 *      样例那个 3 是运气，不是算对的。
 *
 * 复杂度
 *   O(q * 串长)。
 * ────────────────────────────────────────────────────────────
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    string s;
    cin >> s;

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            string t;
            cin >> t;
            s += t;                          // 接在末尾
            cout << s << '\n';
        }
        else if (op == 2) {
            int a, b;
            cin >> a >> b;
            s = s.substr(a, b);              // 从 a 开始，取 b 个（b 是长度！）
            cout << s << '\n';
        }
        else if (op == 3) {
            int a;
            string t;
            cin >> a >> t;
            s.insert(a, t);                  // 插在第 a 个字符前面；a 可以等于 size
            cout << s << '\n';
        }
        else {
            string t;
            cin >> t;
            int p = (int)s.find(t);          // 找不到时 find 返回 string::npos
            cout << (p == (int)string::npos ? -1 : p) << '\n';
        }
    }
    return 0;
}