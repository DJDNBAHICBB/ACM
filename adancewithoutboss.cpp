#include "bits/stdc++.h"
using namespace std;
#define MAXN 6005
int h[MAXN];
int v[MAXN];
vector<int> son[MAXN];
int f[MAXN][2];
void dp(int x)
{
    f[x][0]=0;                                       //为当前点赋值
    f[x][1]=h[x];
    for (int i = 0; i <son[x].size() ; i++) {                      //遍历每一个下属
        int y = son[x][i];
        dp(y);                                                  //一个递归，相当于向下bfs遍历
        f[x][0]+=max(f[y][1],f[y][0]);
        f[x][1]+=f[y][0];
    }

}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n ;i++)           //读取快乐值
        cin >> h[i];
    for (int i = 1; i <n ; i++) {
        int x,y;
        cin >> x >> y;
        son[y].push_back(x);               //y是boss，存入下属
        v[x]=1;                          //标记是否有入度，若无，则为root
    }
    int root;
    for (int i = 1; i <=n ; i++) {
        if(!v[i]) {
            root = i;
            break;
        }
    }
    dp(root);
    cout << max(f[root][1],f[root][0]);
}