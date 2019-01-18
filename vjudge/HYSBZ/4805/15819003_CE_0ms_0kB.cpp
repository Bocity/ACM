#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n) -1; i >= x; --i)
#define endl "\n"
using namespace std;
typedef long long ll;
const ll maxn = 10000000;
int phi[maxn];
bool vis[maxn] = {true, true};
int prime[maxn];
int tot = 0;
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
        phi[i] = phi[i - 1] + phi[i];
    }
}
map<ll,ll> q;
// S[n] = n * (n + 1) / 2  -  \sum2..n S(n/i)
ll S(ll u) {
    if (u < maxn - 1) return phi[u];
    if (q[u]) return q[u];
    ll ans = u * (u + 1) / 2;
    for (ll l = 2, r; l <= u; l += r) {
        r = u / (u / l);
        ans -= (r - l + 1) * S(u / l);
    }
    return q[u] = ans;
}
ll n;
int main() {
    phi_table(maxn);
    cin >> n;
    cout << S(n) << endl;
    return 0;
}
