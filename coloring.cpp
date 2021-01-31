#include <bits/stdc++.h>
using  namespace std;
int dp[100][100];
int main()
{
    memset(dp,INT32_MAX,sizeof(dp));
    char str[100000];
    cin >> str;
    int n= strlen(str);
    for(int i=1;i<=n;i++)
    {
        dp[i][i]=1;
    }
    int mi=100000;
    for(int len =1;len <=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int ends=i+len-1;
            for(int j=i;j<ends;j++)
            {
                if(str[i]!=str[ends] && i!=ends)
                {
                    dp[i][ends]=min(dp[i][ends],dp[i][j]+dp[j+1][ends]);
                }
                else if(str[i]==str[ends] && i!=ends)
                {
                    dp[i][ends]=min(dp[i+1][ends],dp[i][ends-1]);
                }


            }
        }
    }
    cout << dp[1][n] << endl;
}