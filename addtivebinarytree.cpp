#include "bits/stdc++.h"
using namespace std;
typedef long long  ll;
long long dp[40][40];
int root[40][40];
#define max(x,y) x>y?x:y
void print(ll l, ll r) {
    if (l > r)return;
    printf("%lld ", root[l][r]);
    if (l == r)return;
    print(l, root[l][r] - 1);
    print(root[l][r]+1,r);
}
int main()
{
    int N;
    cin >> N;
    for(int i = 1;i <= N;i++)
    {
        cin >> dp[i][i];
        dp[i][i-1]=1;
        root[i][i]=i;
    }
    for(int len = 1;len < N; ++len)
    {
        for(int j = 1;j+len<=N;j++)
        {
            int ends = j+len;
            dp[j][ends]=dp[j][j]+dp[j+1][ends];
            root[j][ends]=j;
            for(int k = j;k<ends;++k)
            {
                if(dp[j][ends]<dp[j][k-1]*dp[k+1][ends]+dp[k][k])
                {
                    dp[j][ends]=dp[j][k-1]*dp[k+1][ends]+dp[k][k];
                    root[j][ends]=k;
                }
            }
        }
    }
    cout << dp[1][N]<<endl;
    print(1,N);

}