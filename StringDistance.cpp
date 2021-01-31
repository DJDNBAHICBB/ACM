#include "bits/stdc++.h"
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
string a;
string b;
int dp[10010][20];
inline int solve()
{
    for(int i=1;i<=a.length();i++)
    {
        for(int j=1;j<=b.length();j++)
        {
            if(a[i]==b[j])
            {
                dp[i][j]=max(dp[i-1][j-1]+1,dp[i-1][j]);
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[a.length()][b.length()];
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        string c;
        cin >> a>> b;
        c=a;
        int n;
        cin >> n;
        while(n--)
        {
            int l,r;
            int min=9999990;
            cin >> l >> r;
            a=c.substr(l-1,r-l+1);
            cout << a.length()+b.length()-2*solve()<<endl;
        }
    }
}