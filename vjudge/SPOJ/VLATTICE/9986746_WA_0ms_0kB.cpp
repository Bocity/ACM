#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define PER(n, i) for (int i = (n - 1); i >= 0; i--)
#define endl "\n"
#define MOD 1000000007
const long maxn = 1000005;
typedef long long ll;
int read() {
    int n = 0, f = 1;
    char ch = getchar();
    while (ch < '0' && ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return n * f;
}
bool vis[maxn];
int prime[maxn];
int mu[maxn];
int tot;
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

int a, b, c, d, k, t;
using namespace std;
int main() {
    init();
    ios::sync_with_stdio(0);
    t = read();
    REP(p, t) {
        b = read();
        ll ans = 0;
        for (int i = 1; i <= b; i++) {
            ans += (ll) mu[i] * (b / i) * (b / i) * (b / i + 3);
        }
        cout << "Case " << p + 1 << ": " << ans + 3 << endl;
    }
    return 0;
}