// 洛谷 P1996 约瑟夫问题
// n 个人围成一圈报数，报到 m 的人出列，下一个人重新从 1 开始报，输出出列顺序。
//
// 核心：queue 里「数到 m 的人出列」= 把前 m-1 个人从队头搬到队尾，
//       然后弹掉现在站在队头的那个。
//
// 两个必须记住的 queue 事实：
//   1) pop() 没有返回值 —— 必须 front() 先取、pop() 再删，成对出现。
//   2) 空队列上 front()/pop() 是未定义行为 —— 必须 while (!q.empty())。
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }

    int i = 0;
    while (!q.empty())
    {
        for (int k = 1; k < m; k++)        // 搬 m-1 次；m = 1 时一次都不循环
        {
            int a = q.front();
            q.pop();
            q.push(a);
        }
        printf(i++ ? " %d" : "%d", q.front());   // 空格放前面 -> 行末不多空格
        q.pop();
    }
    printf("\n");
    return 0;
}