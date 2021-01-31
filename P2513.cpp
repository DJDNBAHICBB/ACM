//
// Created by acer on 2020/9/6.
//

#include "iostream"
#include "stdio.h"
#include "string.h"
#include "algorithm"
#include "queue"
#include "bits/stdc++.h"
using namespace std;
#define mod 10000
int dp[1050][1050];
int main()
{
    int n,k;
    cin >> n >> k;
    dp[1][0] = 1;
    for(int i = 2;i <= n;i++)    //i是数字个数
    {
        int sum = 0;
        for(int j = 0;j <= k;j++)    //j是逆序个数
        {
            (sum += dp[i-1][j])%=mod;        //每增加一个数就可以比i-1增加0~i-1个逆序对
            dp[i][j] = sum;
            if(j >= i - 1)             //如果要求增加的逆序对大于i-1
            {
                (((sum -= dp[i-1][j-i+1])%=mod)+=mod)%=mod;    //找比i-1多几个逆序对再剪掉就是i-1了
            }


        }
    }
    cout << dp[n][k];
}