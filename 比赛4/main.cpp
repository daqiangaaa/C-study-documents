#include <stdio.h>
char g[1005][1005];              /* 网格，按行存成字符串 */
int qx[1000005], qy[1000005];    /* 队列（最大 = 格子总数） */
int dx[4] = {0, 1, 0, -1};       /* 你第 3 课学的表，一模一样 */
int dy[4] = {1, 0, -1, 0};
int main()
{
    int n, m;
    int best=0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", g[i]);            /* 每行读一串，如 "11000" */
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] != '1') continue;   /* 不是没数过的陆地，跳过 */
            /* ---- 发现一块新陆地 ---- */
            ans++;
            int area=1;
            g[i][j] = '2';                  /* 涂色，表示来过了 */
            int head = 0, tail = 0;
            qx[tail] = i;
            qy[tail] = j;
            tail++;
            /* ---- 把这一整片都找出来、都涂掉 ---- */
            while (head < tail)
            {
                int x = qx[head], y = qy[head];
                head++;
                for (int d = 0; d < 4; d++)
                {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;  /* 出界 */
                    if (g[nx][ny] != '1') continue;                        /* 不是陆地 */
                    g[nx][ny] = '2';           /* 涂色 */
                    qx[tail] = nx;
                    qy[tail] = ny;
                    tail++;
                    area++;
                }
            }
            if(area>best)best=area;
        }
    printf("%d\n%d\n", ans,best);
    return 0;
}
