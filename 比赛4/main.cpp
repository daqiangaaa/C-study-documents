#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        for (int k = 1; k < m; k++)
        {
            int a=q.front();
            q.pop();
            q.push(a);
        }
        cout << q.front() << ' ';
        q.pop();
    }
}
