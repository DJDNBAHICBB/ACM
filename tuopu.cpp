#include <bits/stdc++.h>
using namespace std;
#define int long long
int day[101000];
int cnt = 0;
int head[200000];
struct node{
    int next;
    int to;
    int tim;
}nod[200000];
void add(int u,int v,int w)
{
    nod[++cnt].next = head[u];
    nod[cnt].to = v;
    nod[cnt].tim = w;
    head[u] = cnt;
}

int d[200000];
queue<int> q;
signed main()
{
    int N,M,C;
    cin >> N >> M >> C;
    for (int i = 1; i <= N; ++i) {
        cin >> day[i];
    }
    for (int j = 1; j <= C; ++j) {
        int a,b,x;
        cin >> a>> b >> x;
        add(a,b,x);
        ++d[b];
    }
    for (int k = 1; k <= N; ++k) {
        if (!d[k]) q.push(k);
    }
    while (!q.empty())
    {
        int u = q.front();q.pop();
        for (int i = head[u]; i  ; i = nod[i].next) {
            int v = nod[i].to;
            int w = nod[i].tim;
            day[v] = max(day[v],day[u]+w);
            --d[v];
            if (!d[v]) q.push(v);
        }
    }
    for (int l = 1; l <= N; ++l) {
        cout << day[l] << endl;
    }
}
