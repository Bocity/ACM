#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n) -1; i >= x; --i)
#define endl "\n"
#define DE puts("----------")
#define CASE(i, ans) cout << "Case #" << (i) << ": " << (ans) << "\n"
#define lowbit(x) ((x) & (-(x)))
#define sqr(x) ((x) * (x))
#define eps 1e-9
#define PI acos(-1.0)
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
__gnu_pbds::cc_hash_table<string, int> hash1;
__gnu_pbds::gp_hash_table<string, int> hash2;
__gnu_pbds::priority_queue<int> pq;
__gnu_pbds::tree<int, null_type, less<int>, rb_tree_tag> rbtree;
typedef bitset<1005> Bitset;
const int maxn = 20005;
ll n, m, k;
const long long mod = 100000007;
int a[20005];
ll f[20005];
ll g[20005];
ll viss[20005];
int mu[20005];
int vis[20005];
int tot;
int prime[maxn];
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
ll qpow(ll a, ll b, ll p) { // return a^b %p
    ll t = 1;
    for (a %= p; b; b >>= 1LL, a = a * a % p)
        if (b & 1LL) t = t * a % p;
    return t;
}
int main() {
    ios::sync_with_stdio(0);
    init();
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        memset(f, 0, sizeof f);
        memset(vis, 0, sizeof vis);
        memset(viss, 0, sizeof viss);
        memset(g, 0, sizeof g);
        REP(i, 0, n) {
            cin >> a[i];
            viss[a[i]]++;
        }
        PER(i, 1, 1005) {
            ll t = 0;
            for (int j = i; j < 1005; j += i) {
                t += viss[j];
            }
            g[i] += (qpow(2, t, mod) - 1 + mod) % mod;
        }
        REP(i, 1, 1005) {
            for (int j = i; j < 1005; j += i) {
                f[i] += g[j] * 1ll * mu[j / i] % mod;
            }
        }
        ll ans = 0;
        REP(i, 1, 1005) {
            // if (f[i] !=0 ) cout << f[i] << " " << i << endl;
            ans += 1LL * i * (f[i]) % mod;
        }
        cout << ans % mod << endl;
    }
    return 0;
}