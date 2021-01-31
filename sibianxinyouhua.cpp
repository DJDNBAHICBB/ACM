//
// Created by acer on 2020/11/23.
//

//m(i,j)=min{m(i,k-1),m(k,j)}+w(i,j)(i≤k≤j)
//满足对于 i≤i'<j≤j'，有 w(i',j)≤w(i,j')，且对于 i≤i'<j≤j'，有 w(i,j)+w(i',j')≤w(i',j)+w(i,j')
//则m函数具有相同性质，故可以简单的推出m的最优决策点有s(i,j)≤s(i,j+1)≤s(i+1,j+1)
int main() {
    int f[100][100];
    int m[100][100];
    int n, INF = 100;
    for (int i = 1; i <= n; ++i) {
        m[i][i] = i;
    }
    for (int len = 2; len <= n; ++len)  // 枚举区间长度
        for (int l = 1, r = len; r <= n; ++l, ++r) {  // 枚举长度为len的所有区间
            f[l][r] = INF;
            for (int k = m[l][r - 1]; k <= m[l + 1][r]; ++k)
                if (f[l][r] > f[l][k] + f[k + 1][r] + w(l, r)) {
                    f[l][r] = f[l][k] + f[k + 1][r] + w(l, r);  // 更新状态值
                    m[l][r] = k;  // 更新（最小）最优决策点
                }
        }
}
