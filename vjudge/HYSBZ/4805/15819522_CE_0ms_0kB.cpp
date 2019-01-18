#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
#define maxn 10000000
ll phi[maxn + 20];
bool vis[maxn + 20] =  {true,true};
int pri[maxn + 20];
int tot = 0;
void pre() {
    vis[1] = true;
    phi[1] = 1;
    for (int i = 2; i <= maxn; ++i) {
        if (!vis[i]) pri[++tot] = i, phi[i] = i - 1;
        for (int j = 1; j <= tot && pri[j] * i <= maxn; ++j) {
            vis[i * pri[j]] = true;
            if (i % pri[j])
                phi[i * pri[j]] = phi[i] * phi[pri[j]];
            else {
                phi[i * pri[j]] = phi[i] * pri[j];
                break;
            }
        }
    }
    for (int i = 1; i <= maxn; ++i) phi[i] += phi[i - 1];
}

map<ll, ll> q;
// S[n] = n * (n + 1) / 2  -  \sum2..n S(n/i)
ll S(ll u) {
    if (u < maxn - 1) return phi[u];
    if (q[u]) return q[u];
    ll ans = u * (u + 1) / 2;
    for (ll l = 2, r; l <= u; l = r + 1) {
        r = u / (u / l);
        ans -= (r - l + 1) * S(u / l);
    }
    return q[u] = ans;
}
ll n;
int main() {
    pre();
    cin >> n;
    cout << S(n) << endl;
    return 0;
}
