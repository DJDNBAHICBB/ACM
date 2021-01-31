#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 5e6 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int n;
int prime[N], a[N];
bool is_prime[N];
void get_prime(){
    int k = 0;
    memset(is_prime, true, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2 ; i <= N;i++){
        if (is_prime[i]) prime[++k] = i;
        for(int j = 1; j <= k && i * prime[j] <= N;j++){
            is_prime[i * prime[j]] = false;
            if(i % prime[j] == 0) break;
        }
    }
}
int vis[N];
void solve() {
    cin >> n;
    for (int i = 1 ; i <= n; i++) cin >> a[i], vis[a[i]] = 1;
    if (!vis[1]) {
        cout << 1 << endl;
        return;
    }
    get_prime();
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j * j <= a[i]; j++) {
            if (a[i] % j == 0) vis[j] = 1, vis[a[i]/j] = 1;
        }
    }
    for (int i = 1; i <= 5e6; i++) {
        if (!vis[i] && is_prime[i]) {
            cout << i << endl;
            break;
        }
    }
}

int main() {
    solve();

}
