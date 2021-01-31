//
// Created by acer on 2020/9/3.
//

#include "iostream"
#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "queue"
#include "bits/stdc++.h"
using namespace std;
int dp[100000][10];
int cnt;int head[100010];
struct node{
    int next;
    int to;
}a[100010];
void add(int u,int v)
{
    a[++cnt].to = v;
    a[cnt].next = head[u];      //初始为0,作为遍历时的头
    head[u] = cnt;          //好像是叫前向星=-=（图论白痴）
}

int dfs(int u)
{
    dp[u][1]=dp[u][2]=0;dp[u][5]=1;
    for(int i = head[u];i;i = a[i].next)
    {
        int v = a[i].to;
        dfs(v);
        dp[u][5] += dp[v][1];
        dp[u][2] += dp[v][3];
        dp[u][1] += dp[v][2];
    }
    if(head[u] == 0) dp[u][3]=dp[u][4] = 1;
    else
    {
        dp[u][3] = dp[u][4] = INFINITY;
        for(int i = head[u];i;i = a[i].next)
        {
            int v = a[i].to;
            int f1 = dp[v][5];
            int f2 = dp[v][4];
            for(int j = head[u];j;j = a[j].next)
            {
                if(i == j) continue;
                int t = a[j].to;

                f1 += dp[t][2];
                f2 += dp[t][3];
            }
            dp[u][3] = min(dp[u][3],f2);
            dp[u][4] = min(dp[u][4],f1);
        }
        for(int i = 4;i >= 1;i--)
        {
            dp[u][i] = min(dp[u][i],dp[u][i+1]);
        }

    }



}
int main()
{
    int n;
    cin >> n;
    for(int i = 2;i <= n;i++)
    {
        int k;
        cin >> k;
        add(k,i);
    }
    dfs(1);
    cout << dp[1][3] << endl;
}