//
// Created by acer on 2021/2/21.
//
//https://img-blog.csdn.net/20180728201947341?watermark/2/text/aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzM3NjMyOTM1/font/5a6L5L2T/fontsize/400/fill/I0JBQkFCMA==/dissolve/70
/*
① φ(p) = p - 1;
② φ(i * p) = p * φ(i) (i mod p == 0);
③ φ(i * p) = (p - 1) * φ(i) (i mod p != 0);
*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int long long
const int mod  = 10;
#define N 10000050
#define M 10000000
int tot;
int phi[N], pri[N];
void Prepare_Phi() ///欧拉筛求欧拉函数
{
    phi[1] = 1;
    for(int i = 2; i <= M; ++i)
    {
        if(!phi[i])
            pri[++tot] = i, phi[i] = i-1;///公式1
        for(int j = 1; j <= tot; ++j)
        {
            if(i*pri[j] > M)
                break;
            if(!(i%pri[j]))
            {
                phi[i*pri[j]] = phi[i] * pri[j];///公式2
                break;
            }
            else
                phi[i*pri[j]] = phi[i] * (pri[j]-1);///公式3
        }
    }
}
//inline ll phi(ll x)
//{
//    ll ans = x;
//    for(ll i = 2; i * i <= x; ++i)
//    {
//        if(x % i == 0)
//        {
//            ans = ans / i * (i - 1);
//            while(x % i == 0)x /= i;
//        }
//    }
//    if(x > 1)ans = ans / x * (x - 1);
//    return ans;
//}

inline ll modulo(ll x, ll mod){return x < mod ? x : x % mod + mod;}
inline ll pow_(ll a, ll b, ll p)
{
    ll ret = 1;
    while(b)
    {
        if(b & 1)ret = modulo(ret * a, p);
        a = modulo(a * a, p);
        b >>= 1;
    }
    return ret;
}
ll f(ll a, ll b, ll k, ll p)
{
    if(p == 1)return 1;
    if(k == 0)return 1;
    return pow_(a, f(a, a, k - 1, phi[p]), p);
}

signed main()
{
    Prepare_Phi();
    ll a,n;
    cin >> a >> n;
    if (n==0)
    {
        cout << 1%mod << endl;
    }
    ll ans = f(a,a,n,mod)%mod;
    cout << ans << endl;
}