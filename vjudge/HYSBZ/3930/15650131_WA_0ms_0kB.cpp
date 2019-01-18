#include <bits/stdc++.h>
using namespace std;
#define llp(i, x, y) for (int i = x; i < y; ++i) // [x,y) x->y
#define REP llp
#define rlp(i, x, y) for (int i = y - 1; i >= x; --i) // [x,y) y->x
#define PER rlp
#define lp(i, x) for (int i = 0; i < x; ++i) //[0,x）0->x
#define mem(a, x) memset(a, x, sizeof a)
#define endl "\n"
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const ll MOD = 1e9 + 7;
const ll N = 1e6 + 50;
const db eps = 1e-9;
const ll INF = 2e18;
inline ll qpower(ll x, ll p, ll M = MOD) {
    ll ans = 1;
    while (p) {
        if (p & 1) ans = ans * x % M;
        p >>= 1;
        x = x * x % M;
    }
    return ans;
}
inline ll gcd(ll a, ll b) {
    ll x;
    while (b) {
        x = a % b;
        a = b;
        b = x;
    }
    return a;
}
inline ll getInv(ll x, ll M = MOD) {
    return qpower(x, M - 2, M);
}
inline ll modp(ll x, ll p = MOD) {
    return (x % p + p) % p;
} //常数较大
inline ll addp(ll x, ll y, ll p = MOD) {
    return x + y >= p ? x + y - p : x + y;
}
inline ll subp(ll x, ll y, ll p = MOD) {
    return x - y < 0 ? x - y + p : x - y;
}
inline int ifloor(db x) {
    return x > 0 ? int(x + eps) : int(x - eps);
}
inline bool fequal(db x) {
    return x > 0 ? int(x + eps) : int(x - eps);
}
const int maxn = 1e7 + 1;
int mu[maxn];
int prime[maxn];
int tot = 0;
int vis[maxn];
int g[maxn];
map<ll, ll> M;
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
    g[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        g[i] += g[i - 1] + mu[i];
    }
    return;
}
ll calc(ll y, ll n, ll d) {
    ll ans = 0;
    n = n / d / d / y;
    for (ll l = y + 1, r; l <= 2 * y - 1 && l <= n; l = r + 1) {
        if (n / l == 0) break;
        r = min(n / (n / l), y * 2 - 1);
        ans += 1ll * (r - l + 1) * (n / l);
    }
    return ans;
}
ll Smu(ll x) {
    if (x < maxn) return g[x];
    if (M[x]) return M[x];
    ll ans = 1;
    for (ll l = 2, r; l <= x; l = r + 1) {
        r = x / (x / l);
        ans -= (r - l + 1) * Smu(x / l);
    }
    return M[x] = ans;
}
ll n, k, l, h, L;
int main() {
    ios::sync_with_stdio(0);
    init();
    cin >> n >> k >> L >> h;
    ll sz = sqrt(k) + 1;
    ll ans = 0;
    ll temp = 0;
    // for (ll d = k; d <= h; d += k) {
    //     temp = qpower((h / d) - ((l - 1) / d), n);
    //     ans = (ans + temp * (Smu(d / k) - Smu(d / k - 1))) % MOD;
    // }
    L = (L - 1) / k;
    h = h / k;
    for (ll l = 1, r; l <= h; l = r + 1) {
        r = h / (h / l);
        if (l <= L) r = min(r, L / (L / l));
        ans = (ans + (Smu(r) - Smu(l - 1)) * qpower((h / l) - L / l, n) % MOD) % MOD;
    }
    cout << ans << endl;
    return 0;
}