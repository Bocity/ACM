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
const ll MAX = 10000000;
bool zs[MAX + 1];
int pri[MAX + 1], tot, g[MAX + 1], lst[MAX + 1], fp[MAX + 1];
void init() {
    for (int i = 2; i <= MAX; ++i) {
        if (!zs[i]) pri[++tot] = i, lst[i] = g[i] = fp[i] = 1;
        for (int j = 1; j <= tot && i * pri[j] <= MAX; ++j) {
            int x = i * pri[j];
            zs[x] = true;
            if (i % pri[j] == 0) {
                lst[x] = lst[i];
                fp[x] = fp[i] + 1;
                if (lst[x] == 1)
                    g[x] = 1;
                else
                    g[x] = (fp[lst[x]] == fp[x] ? -g[lst[x]] : 0);
                break;
            }
            lst[x] = i;
            fp[x] = 1;
            g[x] = (fp[i] == 1 ? -g[i] : 0);
        }
    }
    for (int i = 1; i <= MAX; ++i) g[i] += g[i - 1];
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
ll n;
int main() {
    ios::sync_with_stdio(0);
    init();
    int t;
    cin >> t;
    ll a = 0, b = 0;
    while (t--) {
        ll ans = 0;
        cin >> a >> b;
        // ll n = min(a, b);
        if (a > b) swap(a, b);
        for (ll l = 1, r; l <= a; l = r + 1) {
            r = min(a / (a / l), b / (b / l));
            ans += 1ll * (a / l) * (b / l) * (g[r] - g[l - 1]);
        }
        cout << ans << endl;
    }
    return 0;
}