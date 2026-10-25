// 输入 n 个整数，输出两行：
//   第 1 行：不同数的个数
//   第 2 行：从小到大，空格隔开，行末不留多余空格
//
// 关键：set = 只有键没有值的 map -> 免费的去重 + 排序，一步到位。
//
// 两条硬禁令：
//   1) 元素进了 set 就不许改（改了会毁掉排序）-> error: assignment of read-only reference
//   2) 没有 s[0] 这种下标 -> error: no match for 'operator[]'
//
// 另外：insert 返回 pair<iterator, bool>，那个 bool 告诉你「到底插进去了没」。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        st.insert(a);
    }

    printf("%d\n", (int)st.size());

    int i = 0;
    for (auto &x : st)                          // set 遍历天生升序
        printf(i++ ? " %d" : "%d", x);          // 空格放前面 -> 末尾没有多余空格
    printf("\n");
    return 0;
}