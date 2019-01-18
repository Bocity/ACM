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
const int maxn = 4e6 + 2;
ll phi[maxn + 2];
bool check[maxn + 2]; // 访问标记
ll prime[maxn + 2];
int tot = 0;
ll sum[maxn + 2];
void phi_table(int n) {
    tot = 0;
    phi[1] = 1;
    sum[1] = 1;
    for (ll i = 2; i <= n; i++) {
        if (!check[i]) {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for (ll j = 0; j < tot; j++) {
            if (i * prime[j] > n) break;
            check[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
    for (int i = 2; i <= maxn; ++i) {
        sum[i] = sum[i - 1] + phi[i];
    }
}
ll n;
int main() {
    ios::sync_with_stdio(0);
    phi_table(maxn);
    ll ans = 0;
    while (cin >> n && n) {
        ans = 0;
        for (ll l = 1, r; l <= n; l = r + 1) {
            r = (n / (n / l));
            ans += (n / l) * (n / l) * (sum[r] - sum[l - 1]);
        }
        ans -= n * (n + 1)/2;
        ans /= 2;
        cout << ans << endl;
    }

    return 0;
}