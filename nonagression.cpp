//
// Created by acer on 2020/7/25.
//

#include "bits/stdc++.h"
using namespace std;
bool tf[1000][1000]={false};
int n ,k;
void dp();
void dfs(int l, int r ,int now)
{

    if(now > n*n-k) return ;
    if(l > n || r>n) return ;
    if( l == n && r== n)
    {
        if(now == n*n-k)
        {
            dp();
        }
    }
    dfs(l+1,r,now);
    dfs(l,r+1,now);
    tf[l][r] = true;
    dfs(l+1,r,now+1);
    dfs(l,r+1,now+1);
    tf[l][r]=false;
}
void dp()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(!tf[i][j])
            {

            }

        }

    }

}

int main()
{
    cin  >> n >> k;

}