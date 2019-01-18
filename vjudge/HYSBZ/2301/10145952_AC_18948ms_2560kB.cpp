#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); i++)
#define PER(n, x, i) for (int i = (n - 1); i >= (x); i--)
#define endl "\n"
#define MOD 1000000007
using namespace std;
const int maxn = 1e5 + 5;
typedef long long ll;
bool vis[maxn];
int prime[maxn];
int mu[maxn];
int pre[maxn];
int tot;
void init() {
    memset(vis, 0, sizeof(vis));
    mu[1] = 1;
    pre[1] = 1;
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
        pre[i] = pre[i - 1] + mu[i];
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
ll cal(ll n, ll m) {
    ll t = min(n, m);
    ll sum = 0;
    int end;
    for (int i = 1; i <= t; i = end + 1) {
        end = min(n / (n / i), m / (m / i));
        sum += ((pre[end] - pre[i - 1]) * (n / i) * (m / i));
    }
    return sum;
}
ll a, b, c, d, k, t, n;
int main() {
    // ios::sync_with_stdio(0);
    init();
    scanf("%lld", &n);
    REP(t, 0, n) {
        scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &k);
        if (k == 0) {
            cout << 0 << endl;
            continue;
        }
        ll A, C, B, D;
        B = b;
        D = d;
        A = a;
        C = c;
        b /= k;
        d /= k;
        ll ans;
        ans = cal(b, d);
        // cout << ans << "----";
        a--;
        c = D;
        a /= k;
        c /= k;
        ll ans2 = 0;
        ans2 = cal(a, c);
        a = A;
        c = C;
        c--;
        a = B;
        a /= k;
        c /= k;
        ll ans3 = 0;
        ans3 = cal(a, c);
        a = A;
        c = C;
        a--;
        c--;
        a /= k;
        c /= k;
        ll ans4 = 0;
        ans4 = cal(a, c);
        printf("%lld\n", ans - ans2 - ans3 + ans4);
    }

    return 0;
}