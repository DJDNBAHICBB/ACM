#include "bits/stdc++.h"
using namespace std;
char f[510][510];
int n,m;
struct node{
    int x,y,t;
};
int dis[200][200];
bool bo[510][510];
node s,e;
queue<node> q;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void bfs(int x,int y)
{
    node a;
    a.x = x;
    a.y = y;
    a.t = 0;
    q.push(a);
    while (!q.empty())
    {
        node c;
        c = q.front();
        bo[c.x][c.y] = true;
        q.pop();
        for(int i = 0;i < 4;i++)
        {
            node d;
            d.x = c.x + dx[i];
            d.y = c.y + dy[i];

            d.t = c.t + 1;
            if(d.x <= n && d.x >= 1 && d.y >= 1 && d.y <= m && d.t<dis[d.x][d.y] && f[d.x][d.y] == '.')
            {
                dis[d.x][d.y] = d.t;
                q.push(d);
            }
        }
    }
}

int main()
{
    memset(dis,0x3f3f,sizeof(dis));
    cin >>n >>m;

    cin >> s.x >> s.y;
//    cout << s.x << ' ' << s.y <<endl;
    cin >> e.x >> e.y;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= m; ++i) {
            cin >> f[k][i];
        }
    }
    bfs(s.x,s.y);
    int ans = dis[e.x][e.y]*100;
    if (ans != -1263225700)
        cout << ans << endl;
    else
        cout << -1 << endl;
}