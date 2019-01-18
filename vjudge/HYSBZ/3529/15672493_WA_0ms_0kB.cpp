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
const ll MOD = 1 << 31;
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
const int maxn = 2e5 + 1;
ll mu[maxn];
int prime[maxn];
int tot = 0;
int vis[maxn];
ll d[maxn];
ll z[maxn];
struct ques {
    int n, m, id, a;
} q[maxn];
bool cmp(ques x, ques y) {
    return x.a < y.a;
}
ll ans[maxn];
ll p[maxn];
void init() {
    memset(vis, 0, sizeof(vis));
    mu[1] = 1;
    d[1] = 1;
    z[1] = 1;
    tot = 0;
    p[1] = 1;
    for (int i = 2; i < maxn; i++) {
        p[i] = i;
        if (!vis[i]) {
            prime[tot++] = i;
            mu[i] = -1;
            d[i] = i + 1;
            z[i] = 1 + i;
        }
        for (int j = 0; j < tot; j++) {
            if (i * prime[j] >= maxn) break;
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                z[i * prime[j]] = z[i] * prime[j] + 1;
                d[i * prime[j]] = d[i] / z[i] * z[i * prime[j]];
                break;
            }
            mu[i * prime[j]] = -mu[i];
            d[i * prime[j]] = d[i] * d[prime[j]];
            z[i * prime[j]] = (1 + prime[j]);
        }
    }
    return;
}
// ll calc(ll y, ll n, ll d) {
//     ll ans = 0;
//     n = n / d / d / y;
//     for (ll l = y + 1, r; l <= 2 * y - 1 && l <= n; l = r + 1) {
//         if (n / l == 0) break;
//         r = min(n / (n / l), y * 2 - 1);
//         ans += 1ll * (r - l + 1) * (n / l);
//     }
//     return ans;
// }
// ll Smu(ll x) {
//     if (x < maxn) return g[x];
//     if (M[x]) return M[x];
//     ll ans = 1;
//     for (ll l = 2, r; l <= x; l = r + 1) {
//         r = x / (x / l);
//         ans -= (r - l + 1) * Smu(x / l);
//     }
//     return M[x] = ans;
// }
ll c[maxn << 1];
void add(int x, ll val) {
    for (; x <= maxn; x += (x & -x)) {
        c[x] += val;
        c[x] %= MOD;
    }
}
ll query(int x) {
    ll ans = 0;
    for (; x; x -= (x & -x)) {
        ans += c[x];
    }
    ans %= MOD;
    return ans;
}
ll n, k, l, h, L;
bool cmp2(int x, int y) {
    return d[x] < d[y];
}
int main() {
    ios::sync_with_stdio(0);
    // freopen("1.txt","w",stdout);
    init();
    int t;
    cin >> t;
    int pos = 0;
    while (t--) {
        cin >> q[pos].n >> q[pos].m >> q[pos].a;
        q[pos].id = pos;
        pos++;
    }
    sort(q, q + pos, cmp);
    sort(p, p + maxn, cmp2);
    int j = 1;
    REP(i, 0, pos) {
        for (; j <=maxn && d[p[j]] <= q[i].a; ++j) {
            for (int k = p[j]; k <= maxn; k += p[j]) {
                add(k, d[p[j]] * mu[k / p[j]]);
            }
        }
        ll lst = 0, now;
        for (int l = 1, r; l <= maxn; l = r + 1) {
            if (l > min(q[i].m, q[i].n)) break;
            r = min(q[i].m / (q[i].m / l), q[i].n / (q[i].n / l));
            now = query(r);
            ans[q[i].id] += (now - lst) % MOD * (q[i].m / l) * (q[i].n / l) % MOD;
            ans[q[i].id] %= MOD;
            lst = now;
        }
    }
    REP(i, 0, pos) {
        cout << ans[i] % MOD << endl;
    }
    return 0;
}