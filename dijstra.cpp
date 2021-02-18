//
// Created by acer on 2021/2/16.
//
//建图，优先队列用来存经过的点，前向星确定接下来的点，类似bfs。

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6+9;
int cnt =0 ;
int n,m,rt;
int head[maxn];
int dis[maxn];
int vis[maxn];
struct node{
    int to,next,w;
}a[maxn];
struct Node{
    int id,w;
    friend bool operator<(const Node A,const Node B){
        return A.w>B.w;
    }
};
void add(int u,int v,int w)
{
    a[++cnt].next = head[u];
    a[cnt].to = v;
    a[cnt].w = w;
    head[u] = cnt;
}
priority_queue<Node> Q;
void dijkstra(){
    for(int i=1;i<=n;i++) dis[i]=2147483647;
    int p;
    Q.push((Node){rt,0}),dis[rt]=0;      //起点
    while(!Q.empty()){
        Node tmp=Q.top();
        Q.pop();
        p=tmp.id;
        if(vis[p]) continue;
        vis[p]=1;
        for(int i=head[p];i;i=a[i].next){
            int v=a[i].to;
            if(dis[p]+a[i].w<dis[v]) {
                dis[v]=dis[p]+a[i].w;
                Q.push((Node){v,dis[v]});
            }
        }
    }
}

signed main()
{

    cin >> n >> m >> rt;
    while (m--)
    {
        int u,v,w;
        cin >> u >> v >> w;
        add(u,v,w);
    }
    dijkstra();
    for (int i = 1; i <= n; ++i) {
        cout << dis[i] << ' ';
    }
}
