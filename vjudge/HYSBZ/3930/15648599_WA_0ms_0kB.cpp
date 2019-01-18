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
const int maxn = 2e6 + 1;
ll n, k, l, h;
map<ll,ll>F;
map<ll,ll>f;
int main() {
    ios::sync_with_stdio(0);
    cin >> n >> k >> l >> h;
    if (k > h){
      cout << 0 << endl;
      return 0;
    }
    if (l == h){
      if (k == l){
        cout << 1 << endl;
        return 0;
      }else{
        cout << 0 << endl;
        return 0;
      }
    }
    ll len = h - l + 1;
    h /= k;
    l /= k;
    if (l == 0){
      l == 1;
    }
    for (ll fuck = len; fuck >= 1; --fuck) {
        ll tmp = 0;
        for (ll x = l + (fuck - l % fuck) % fuck; x <= h; x += fuck) {
            tmp++;
        }
        F[fuck] = qpower(tmp, n);
    }
    for (ll fuck = len; fuck >= 1; --fuck) {
        f[fuck] = F[fuck];
        for (ll x = l + (fuck - l % fuck) % fuck + fuck; x <= h; x += fuck) {
            f[fuck] = (f[fuck] - F[x] + MOD) % MOD;
        }
    }
    cout << (f[1] + MOD) % MOD << endl;
    return 0;
}