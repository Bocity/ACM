#include <bits/stdc++.h>
#define FOR(i, x, n) for (int i = (x); i < (n); i++)
#define REP(i, x, n) for (int i = (x); i < (n); i++)
#define PER(n, x, i) for (int i = (n - 1); i >= (x); i--)
#define mems(n, x) memset(n, sizoef n, (x);
#define endl "\n"
#define MOD 1000000007
using namespace std;
const int maxn = 500005;
typedef long long ll;
long long p;

bool vis[maxn];
int prime[maxn];
int mu[maxn];
int sum[maxn];
int tot;
void init() {
    memset(vis, 0, sizeof(vis));
    memset(sum, 0, sizeof(sum));
    mu[1] = 1;
    sum[1] = 1;
    prime[0] = 0;
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
        sum[i] = sum[i - 1] + mu[i];
    }
    return;
}
int read() {
    int n = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return n * f;
}
ll a, b, c, d, k, t, n, m;
ll cal(ll n, ll m) {
    ll t = min(n, m);
    ll ans = 0;
    int end;
    for (int i = 1; i <= t; i = end + 1) {
        ll a = n / i, b = m / i;
        end = min(n / a, m / b);
        ans += a * b * (sum[end] - sum[i - 1]);
    }
    return ans;
}

int main() {
    // ios::sync_with_stdio(0);
    init();
    scanf("%lld%lld", &a, &b);
    ll ans = 0;
    for (int i = 1; i <= min(a, b); i++) {
        ans += cal(a / i, b / i) * (2 * (i - 1) + 1);
    }
    printf("%lld\n", ans);

    return 0;
}