#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); i++)
#define PER(n, x, i) for (int i = (n - 1); i >= (x); i--)
#define endl "\n"
#define MOD 1000000007
using namespace std;
const long maxn = 1000005;
typedef long long ll;
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
ll a, b, c, d, k, t, n;
int main() {
    ios::sync_with_stdio(0);
    init();
    n = read();
    REP(t, 0, n) {
        a = read();
        b = read();
        c = read();
        d = read();
        k = read();
        b /= k;
        d /= k;
        ll A, C, B, D;
        B = b;
        D = d;
        A = a;
        C = c;
        if (b > d) swap(b, d);
        ll ans = 0;
        for (int i = 1; i <= b; i++) {
            ans += (ll) mu[i] * (b / i) * (d / i);
        }
        // cout << ans << "----";
        a--;
        c = D;
        a /= k;
        c /= k;
        ll ans2 = 0;
        if (a > c) swap(a, c);
        for (int i = 1; i <= a; i++) {
            ans2 += (ll) mu[i] * (a / i) * (c / i);
        }
        a = A;
        c = C;
        c--;
        a = B;
        a /= k;
        c /= k;
        ll ans3 = 0;
        if (a > c) swap(a, c);
        for (int i = 1; i <= a; i++) {
            ans3 += (ll) mu[i] * (a / i) * (c / i);
        }
        a = A;
        c = C;
        a--;
        c--;
        a /= k;
        c /= k;
        ll ans4 = 0;
        if (a > c) swap(a, c);
        for (int i = 1; i <= a; i++) {
            ans4 += (ll) mu[i] * (a / i) * (c / i);
        }
        cout << ans - ans2 - ans3 + ans4 << endl;
    }

    return 0;
}