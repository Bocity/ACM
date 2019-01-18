#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); i++)
#define PER(n, x, i) for (int i = (n - 1); i >= (x); i--)
#define mems(n, x) memset(n, sizoef n, (x);
#define endl "\n"
#define MOD 1000000007
using namespace std;
const int maxn = 300005;
typedef long long ll;
long long p;

bool vis[maxn];
int prime[maxn];
int mu[maxn];
int cnt[maxn];
long long fac[maxn];
long long inv[maxn];
long long F[maxn];
int tot;
void Gcd(ll a, ll b, ll &d, ll &x, ll &y) {
    if (!b) {
        d = a;
        x = 1;
        y = 0;
    } else {
        Gcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}
ll qpow(ll a, ll n, ll m) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        n >>= 1;
    }
    return ans;
}
ll Inv(ll a, ll n) {
    ll d, x, y;
    Gcd(a, n, d, x, y);
    return d == 1 ? (x + n) % n : -1;
}

void init() {
    memset(vis, 0, sizeof(vis));
    mu[1] = 1;
    prime[0] = 0;
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
        // cnt[i] = sum[i - 1] + mu[i];
    }
    fac[0] = 1;
    inv[0] = 1;
    REP(i, 1, maxn) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= MOD;
        inv[i] = Inv(fac[i], MOD);
    }
}
ll a, b, c, d, k, t, n, m;

int main() {
    // ios::sync_with_stdio(0);
    init();
    while (scanf("%lld%lld%lld", &n, &m, &k) != EOF) {
        memset(cnt, 0, sizeof(cnt));
        int num;
        REP(i, 0, n) {
            scanf("%d", &num);
            cnt[num]++;
        }
        REP(i, 1, m + 1) {
            for (int j = i + i; j <= m; j += i) {
                cnt[i] += cnt[j];
            }
        }
        REP(d, 1, m + 1) {
            if (cnt[d] < n - k) {
                F[d] = 0;
                continue;
            }
            ll t = (inv[n - k] * inv[cnt[d] + k - n]) % MOD;
            t = (fac[cnt[d]] * t) % MOD;
            F[d] = t * ((qpow((m / d) - 1, cnt[d] + k - n, MOD) * qpow(m / d, n - cnt[d], MOD)) % MOD) % MOD;
        }
        ll res;
        REP(x, 1, m + 1) {
            res = 0;
            for (int d = x; d <= m; d += x) {
                res += mu[d / x] * F[d];
                res = (res + MOD) % MOD;
            }
            if (x == m) {
                printf("%lld\n", res);
            } else
                printf("%lld ", res);
        }
    }

    return 0;
}