//
// Created by SANZONG on 2020/7/29.
//

#include "bits/stdc++.h"

using namespace std;
const int MAXN = 100000;
#define int long long
int fa[MAXN];
int find(int x)
{
    if(x == fa[x])
        return x;
    else{
        fa[x] = find(fa[x]);  //父节点设为根节点
        return fa[x];         //返回父节点
    }
}
void init(int n)
{
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
}
void merge(int i, int j)
{
    fa[find(i)] = find(j);
}