//
// Created by SANZONG on 2020/8/7.
//


#include "bits/stdc++.h"

#define int long long
using namespace std;
#define MAXN 400005
typedef long long ll;
ll a[MAXN];
ll dp[MAXN][2];
ll pre[MAXN];
ll tree[MAXN << 2][4];

inline int ls(int p) { return p << 1; }

inline int rs(int p) { return p << 1 | 1; }

inline void push_up_max(int root, int id) {
    tree[root][id] = max(tree[ls(root)][id], tree[rs(root)][id]);
}

void build(ll p, ll l, ll r) {
    if (l == r) {
        tree[p][1] = tree[p][2] = tree[p][3] = -INT64_MAX;
        if (l == 0)
            tree[p][2] = 0;
        return;
    }
    ll mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    push_up_max(p, 1);
    push_up_max(p, 2);
    push_up_max(p, 3);
}

void update(ll pos, ll l, ll r, ll p, ll id, ll w) {
    if (l == r) {
        tree[p][id] = w;
        return;
    }
    if (l > r) return;

    int mid = (l + r) >> 1;
    if (pos <= mid) update(pos, l, mid, ls(p), id, w);
    else update(pos, mid + 1, r, rs(p), id, w);
    push_up_max(p, id);
}

ll query(ll ql, ll qr, ll p, ll l, ll r, ll id) {
    ll res = -INT64_MAX;
    if (ql <= l && qr >= r) return tree[p][id];
    push_up_max(p,id);
    ll mid = (l + r) >> 1;
    if (ql <= mid) res = max(res, query(ql, qr, ls(p), l, mid, id));
    if (qr > mid) res = max(res, query(ql, qr, rs(p), mid + 1, r, id));
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for (int l = 0; l <= n; ++l) {
        dp[l][1] = dp[l][0] = -INT64_MAX;
//        cout << -INT64_MAX << endl;
    }
    dp[0][0] = 0;
    build(1, 0, n);
    for (int j = 1; j <= n; ++j) {
        if (j -k - 1>=0 ) {
            dp[j][1] = max(query(0, j - k - 1, 1, 0, n, 3) + pre[j],
                           query(0, j - k - 1, 1, 0, n, 2) + pre[j]);
        }
        dp[j][0] = max(query(max(j - k, 0ll),j-1 , 1, 0, n, 1)  + 2 * pre[j],
                       query(max(j - k,0ll), j-1, 1, 0, n, 2) + pre[j]);

        if (j > k) update(j, 0, n, 1, 1, dp[j][1] - 2 * pre[j]);
        update(j, 0, n, 1, 2, dp[j][0] - pre[j]);
        update(j, 0, n, 1, 3, dp[j][1] - pre[j]);
//        cout << dp[j][0] << ' ' << dp[j][1] << endl;
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}
