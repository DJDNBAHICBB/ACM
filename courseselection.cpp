#include "bits/stdc++.h"
using namespace std;
#define MAXN 305
vector<int> son[MAXN];
int val[MAXN][MAXN];
int f[MAXN][MAXN];
int N,M;
void dp(int x)
{
    for (int i = 0; i <son[x].size() ; i++) {
        int ny = son[x][i];
        dp(ny);
        for(int j = M;j >= 1; j--)
        {
            for(int k=j-1;k>=0;k--)
            {
                f[x][j]=max(f[x][j],f[ny][k]+f[x][j-k-1]+val[x][ny]);
            }
        }
    }
}






int main()
{
    cin >> N >> M ;
    for (int i = 1; i <= N; i++) {
        int x,y ;
        cin >> x >> y;
        son[x].push_back(i);
        val[x][i]=y;
    }
    dp(0);
    cout << f[0][M];
}