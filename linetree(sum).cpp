//
// Created by SANZONG on 2020/8/7.
//

#include "bits/stdc++.h"
using namespace std;
#define MAXN 100005
typedef long long ll;
ll a[MAXN*4];
ll ans[4*MAXN];
int tag[1000005];
inline int ls (int p) {return  p<<1;}
inline int rs (int p) {return p<<1|1;}
void push_up_sum(int p) {ans[p] = ans[ls(p)] + ans[rs(p)];}
//void push_up_min(int p) {ans[p] = min( ans[ls(p)],ans[rs(p)]);}
void build(ll p, ll l , ll r)
{
    tag[p] = 0;
    if( l == r) {ans[p] = a[l];return;}
    ll mid = (l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    push_up_sum(p);
}
inline void f(ll p, ll l, ll r, ll k)
{
    tag[p] = tag[p] + k;
    ans[p] = ans[p] + k * (r-l+1);
}
inline void push_down(ll p, ll l, ll r)
{
    ll mid = (l+r)>>1;
    f(ls(p),l,mid,tag[p]);
    f(rs(p),mid+1,r,tag[p]);
    tag[p] = 0;
}
inline void update(ll nl, ll nr , ll l, ll r, ll p, ll k)
{
    if(l >= nl && r <= nr)
    {
        ans[p] += k * (r-l+1);
        tag[p] += k;
        return;
    }
    push_down(p , l, r);
    ll mid = (l+r) >> 1;
    if(nl <= mid) update(nl,nr,l,mid,ls(p),k);
    if(nr > mid) update(nl,nr,mid+1,r,rs(p),k);
    push_up_sum(p);
}
ll query(ll ql,ll qr,ll p, ll l, ll r)
{
    ll res = 0;
    if(ql <= l && qr >= r) return ans[p];
    ll mid = (l + r)>> 1;
    push_down(p,l,r);
    if(ql <= mid) res+= query(ql,qr,ls(p),l,mid);
    if(qr > mid) res+= query(ql,qr,rs(p),mid+1,r);
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n; i++)
    {
        cin >> a[i];
    }
    build(1,1,n);
    for(int i = 1;i <= m ;i++)
    {
        int flag ;
        cin >> flag ;
        switch (flag) {
            case 1: {
                int x,y,k;
                cin >> x >> y >> k;
                update(x,y,1,n,1,k);
                break;
            }
            case 2: {
                int a,b;
                cin >> a >> b;
                ll res = query(a,b,1,1,n);
                cout << res<<endl;
                break;
            }

        }
    }
    return 0;
}
