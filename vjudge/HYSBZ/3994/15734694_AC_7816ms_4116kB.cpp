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
ll k;
const int maxn = 1e5 + 1;
int prime[maxn + 2];
int tot = 0;
bool vis[maxn + 2];
ll mu[maxn + 2];
ll d[maxn + 2];
ll c[maxn + 2];
void init() {
    memset(vis, 0, sizeof(vis));
    tot = 0;
    vis[0] = 1;
    vis[1] = 1;
    mu[0] = 0;
    mu[1] = 1;
    d[1] = 1;
    d[0] = 0;
    c[1] = 1;
    c[0] = 0;
    for (ll i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
            mu[i] = -1;
            d[i] = 2;
            c[i] = 1;
        }
        for (ll j = 0; j < tot; j++) {
            if (i * prime[j] >= maxn) break;
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                d[i * prime[j]] = d[i] / (c[i] + 1) * (c[i] + 2);
                c[i * prime[j]] = c[i] + 1;
                break;
            }
            mu[i * prime[j]] = -mu[i];
            d[i * prime[j]] = d[i] * d[prime[j]];
            c[i * prime[j]] = 1;
        }
    }
    for (ll i = 1; i <= maxn; ++i) {
        mu[i] = (mu[i - 1] + mu[i]);
        d[i] = (d[i] + d[i - 1]);
    }
    return;
}
ll n, m;
ll calc2(ll n, ll m) {
   return  d[n] * d[m];
}
int t;
int main() {
    ios::sync_with_stdio(0);
    init();
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (n < m) {
            swap(n, m);
        }
        ll ans = 0;
        for (ll l = 1, r; l <= m; l = r + 1) {
            r = min(n / (n / l), m / (m / l));
            ans += (mu[r] - mu[l - 1]) * calc2(n / l, m / l);
        }
        cout << ans << endl;
    }
    return 0;
}