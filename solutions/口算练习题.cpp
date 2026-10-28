/*
 * 口算练习题（洛谷 P1957）
 * ────────────────────────────────────────────────────────────
 * 题意
 *   每行给出一次口算记录，两种格式：
 *     a 64 46      ← 第一个字符是运算类型 a/b/c，后面是两个运算数
 *     275 125      ← 只有两个数，沿用上一次的运算类型
 *   运算类型：a = 加，b = 减，c = 乘。运算数非负且 < 10000。
 *   每次输出两行：算式（如 64+46=110），和这个算式的长度（负号也算一个字符）。
 *
 * 思路
 *   1) 先读成一个 string first，再判断它是运算类型还是数字。
 *      因为 "a" 和 "275" 从输入流里看都是「一个词」，
 *      先当字符串读进来、再看长度是不是 1，就不会把类型判错。
 *   2) op 必须声明在循环外面 —— 只有这样才能"沿用上一次"。
 *   3) 算式拼好后，长度直接问 string 要：line.size()。
 *      负号、"+"、"=" 都自动算进去了，不用手数。
 *
 * 踩过的坑
 *   1) 我用 char 存运算数。运算数最多 4 位数，而 cin >> char 只读 1 个字符：
 *      读 "64" 只拿到 '6'，'4' 留在流里，后面整个输入全部错位。
 *   2) (string)t —— std::string 没有从 int 的构造函数，要 to_string(t)。
 *   3) (int)a 想把字符串转成数字 —— 强转只在数值类型之间成立，
 *      string 转数字要用 stoll / stoi。
 *   4) char z, c; 声明在 while 里面，else 分支从没给 c 赋值 → 栈垃圾。
 *   5) 拼算式时漏了 "="，输出变成 64+46=110 少了等号（还会让长度算错）。
 *
 * 复杂度
 *   O(n)，n 是行数。
 * ────────────────────────────────────────────────────────────
 */
#include <bits/stdc++.h>
using namespace std;

void solve(char op, long long a, long long b)
{
    long long r;
    char sym;
    if      (op == 'a') { r = a + b; sym = '+'; }
    else if (op == 'b') { r = a - b; sym = '-'; }
    else                { r = a * b; sym = '*'; }

    string line = to_string(a) + sym + to_string(b) + "=" + to_string(r);
    cout << line << '\n' << line.size() << '\n';
}

int main()
{
    int n;
    cin >> n;

    char op = 'a';                           // ★ 在循环外面，才能沿用上一次

    for (int i = 0; i < n; i++) {
        string first;
        cin >> first;

        long long a, b;
        if (first.size() == 1 && first[0] >= 'a' && first[0] <= 'c') {
            op = first[0];                   // 这一行带运算类型
            cin >> a >> b;
        } else {
            a = stoll(first);                // 这一行只有两个数："275" → 275
            cin >> b;
        }

        solve(op, a, b);
    }
    return 0;
}