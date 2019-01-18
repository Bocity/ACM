#include <bits/stdc++.h>
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
typedef long long ll;
typedef bitset<1005> Bitset;
const ll maxn = 1000100;
int phi[maxn];
bool vis[maxn] = {true, true};
int prime[maxn];
int tot = 0;
ll sum[maxn];
void phi_table(int n) {
    tot = 0;
    phi[1] = 1;
    phi[0] = 0;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < tot && (ll) i * prime[j] < maxn; j++) {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            } else {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
    REP(i, 1, maxn) {
        sum[i] = sum[i - 1] + phi[i];
    }
}
const long long mod = 1000000007;
int a[10000];
// S[n] = n * (n + 1) / 2  -  \sum2..n S(n/i)
ll S(ll u) {
    if (u < maxn) return sum[u];
    ll ans = u * (u + 1) / 2;
    for (ll l = 2, r; l < u; l += r) {
        r = u / (u / l);
        ans -= (r - l + 1) * S(u / l);
    }
    return ans;
}
ll n;
int main() {
    ios::sync_with_stdio(0);
    phi_table(maxn);
    cin >> n;
    cout << S(n) << endl;
    return 0;
}
