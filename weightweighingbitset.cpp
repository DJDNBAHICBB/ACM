//
// Created by acer on 2020/7/24.
//
#include "bits/stdc++.h"
int n,m;
using namespace std;
int wei[100000];
int count(int x)                //找出有几位是1
{
    int cnt = 0;
    for(int i = 0 ;i < n ;i++)
    {
        if(x& (1 << i)) cnt++;
    }
    return cnt;
}
int main()
{
    int ans = 0;
    cin >> n >> m;
    for(int i =0 ;i<n;i++)
    {
        cin >> wei[i];
    }
    for(int i = 0;i <(1 << n)  ; i++)        //有2^n-1种方案
    {
        if(count(i) == n-m)                //列举所有满足条件的方案
        {
            bitset<2010> b;
            b[0]=1;
            for(int j = 0;j < n;j++)
            {
                if(i & (1 << j))
                {
                    b = b | b << wei[j];        //或操作相当于给b << wei[j]位置1
                }

            }
            ans = max (ans , (int)b.count());
        }

    }
    cout << ans-1;
}
