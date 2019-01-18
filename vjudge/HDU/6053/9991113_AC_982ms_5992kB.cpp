#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define PER(n, i) for (int i = (n - 1); i >= 0; i--)
#define endl "\n"
#define MOD 1000000007
using namespace std;
const long maxn = 200005;
typedef long long ll;
int read() {
    int n = 0, f = 1;
    char ch = getchar();
    while (ch < '0' && ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return n * f;
}
bool vis[maxn];
ll prime[maxn];
int mu[maxn];
int tot;
void init() {
    memset(vis, 0, sizeof(vis));
    mu[1] = 1;
    tot = 0;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < tot; j++) {
            if (i * prime[j] >= maxn) break;
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            } else {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
    return;
}
ll Pow(ll a, ll b) {
    ll res = 1;
    for (ll w = a; b; b >>= 1, w = w * w % MOD)
        if (b & 1) res = (res * w) % MOD;
    return res;
}
ll a, b, c, d, k, t, n, minn;
int cnt[maxn << 1];
int sum[maxn << 1];
int main() {
    init();
    ios::sync_with_stdio(0);
    cin >> t;
    REP(p, t) {
        minn = maxn;
        memset(sum, 0, sizeof sum);
        memset(cnt, 0, sizeof cnt);
        cin >> n;
        REP(i, n) {
            ll x;
            cin >> x;
            cnt[x]++;
            minn = min(minn, x);
        }
        ll ans = 0;
        for (ll i = 1; i < maxn * 2; i++) sum[i] = sum[i - 1] + cnt[i];
        for (ll i = 2; i <= minn; i++) {
            ll temp = 1;
            if (mu[i]) {
                for (int j = i; j < maxn; j += i) {
                    temp = (temp * Pow(j / i, sum[j + i - 1] - sum[j - 1])) % MOD;
                }
            }
            ans = ((ans - (temp * mu[i]) % MOD) + MOD) % MOD;
        }
        cout << "Case #" << p + 1 << ": " << ans << endl;
    }
    return 0;
}