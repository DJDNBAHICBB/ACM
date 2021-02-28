#include<cstdio>

#define N 2005
#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b
using namespace std;
int up[N][N], left[N][N], right[N][N], ansa, ansb, a[N][N], m, n;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            up[i][j] = 1, left[i][j] = j, right[i][j] = j, scanf("%d", &a[i][j]);// up 初值，读入，left/right 最初值

    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= m; j++)
            if (a[i][j] ^ a[i][j - 1])
                left[i][j] = left[i][j - 1];
    for (int i = 1; i <= n; i++)
        for (int j = m; j > 1; j--)
            if (a[i][j] ^ a[i][j - 1])
                right[i][j - 1] = right[i][j];//left/right初值，即（i，j）点向左/右的最大宽度

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (i > 1 && a[i][j] ^ a[i - 1][j])
                up[i][j] = up[i - 1][j] + 1, left[i][j] = max(left[i][j],
                                                              left[i - 1][j]), right[i][j] = min(right[i][j],
                                                                                                 right[i - 1][j]);
            int a = right[i][j] - left[i][j] + 1;
            int b = min(a, up[i][j]);
            ansa = max(ansa, b * b);
            ansb = max(ansb, a * up[i][j]);
        }
    printf("%d\n%d", ansa, ansb);
}