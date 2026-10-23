#include <stdio.h>
long long a[1005][1005];
long long s[1005][1005];
int main()
{
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++)
            scanf("%lld", &a[i][j]);}
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
    for (int k = 0; k < q; k++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        long long ans=0;
            ans=s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1];
        printf("%lld\n", ans);
    }
    return 0;
}
