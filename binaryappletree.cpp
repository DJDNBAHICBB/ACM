#include "bits/stdc++.h"
using namespace std;
#define MAXN 120
int keep;
int visited[MAXN]={0};
vector<int> son[MAXN];
int f[MAXN][100];
int val[MAXN][MAXN];
void dp(int x)
{
    visited[x]=1;
    for (int i = 0; i < son[x].size(); i++) {
        if(visited[son[x][i]]!=1)
        {
            int ny=son[x][i];

            dp(ny);
            for (int j = keep; j >=1 ; j--) {                   //父节点保留的
                for (int k = j-1; k >=0 ; k--) {                //k子树保留的
                    f[x][j]=max(f[x][j],f[ny][k]+f[x][j-k-1]+val[ny][x]);           //树上背包
                }
            }
        }

    }
    return;
//    for(int i=0;i<son[x].size();i++)
//    {
//        int y = son[x][i];
//        dp(y);
//        for(int j=keep+1;j>=1;j--)
//        {
//        for(int k = j-1;k>=1;k--)
//        {
//            f[x][j]=max(f[x][j],f[x][j-k]+f[y][k]);
//        }
//    }
//    }
}
int main()
{
    int N;
    int value;
    cin >> N >> keep;
    for (int i = 1; i <N ; i++) {
        int x,y;
        cin >> x >> y >> value;
        son[x].push_back(y);
        son[y].push_back(x);
        val[y][x]=value;
        val[x][y]=value;
    }
    dp(1);
    cout << f[1][keep];
}