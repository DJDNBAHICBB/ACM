//
// Created by acer on 2021/2/18.
//

//
// Created by SANZONG on 2020/7/29.
//

#include "bits/stdc++.h"
using namespace std;
struct graph{
    int s,e, v;
}cld[11000];
int f[11000];
int find(int k)
{
    if(f[k] == k) return k;
    return f[k] = find(f[k]);
}
bool cmp(graph a, graph b)
{
    return a.v<b.v;
}
int main()
{
    int N,M,K;
    cin >> N >> M >> K;
    for(int i=1;i <= N ;i++)
    {
        f[i] = i;
    }
    for(int i = 1;i <= M ;i++)
    {
        cin >> cld[i].s >> cld[i].e >> cld[i].v;
    }

    sort(cld+1,cld+1+M,cmp);
    int cnt =0 , sum =0;
    for(int i = 1;i <= M ;i++)
    {
        if( find(cld[i].e) != find(cld[i].s) )         //不成环就能加
        {
            f[find(cld[i].e)] = find(cld[i].s);
            sum += cld[i].v;
            cnt++;
        }
        if(cnt >= N-K)
            break;

    }

    cout << sum;
}