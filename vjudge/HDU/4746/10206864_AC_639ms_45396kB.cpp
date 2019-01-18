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
int sum[20][maxn];
int tot;
int cnt[maxn];
void init() {
    memset(vis, 0, sizeof(vis));
    memset(sum, 0, sizeof(sum));
    mu[1] = 1;
    // pre[1] = 1;
    prime[0] = 0;
    tot = 0;
    cnt[1] = 0;
    for (int i = 2; i < maxn; i++) {
        if (!vis[i]) {
            prime[tot++] = i;
            mu[i] = -1;
            cnt[i] = 1;
        }
        for (int j = 0; j < tot; j++) {
            if (i * prime[j] >= maxn) break;
            vis[i * prime[j]] = true;
            cnt[i * prime[j]] = cnt[i] + 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            } else {
                mu[i * prime[j]] = -mu[i];
            }
        }
        // pre[i] = pre[i - 1] + mu[i];
    }
    return;
}
void init2() {
    FOR(i, 1, maxn) {
        for (int j = i; j < maxn; j += i) {
            sum[cnt[i]][j] += mu[j / i];
        }
    }
    // sum[i][j]表示所有能整除j的质因子个数<=i的(x,y)的对数
    FOR(j, 1, maxn) {
        FOR(i, 1, 20) {
            sum[i][j] += sum[i - 1][j];
        }
    }
    // sum[i][j]表示sum[i][0]+sum[i][1]+...+sum[i][j]的前缀和
    FOR(j, 1, maxn) {
        FOR(i, 0, 20) {
            sum[i][j] += sum[i][j - 1];
        }
    }
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
        ans += a * b * (sum[p][end] - sum[p][i - 1]);
    }
    return ans;
}

int main() {
    // ios::sync_with_stdio(0);
    init();
    init2();
    // ll ss = 0;
    // for (int i = 1; i < maxn; i++) ss = max((ll) cnt[i], ss);
    // cout << ss << endl;
    scanf("%lld", &n);
    REP(t, 0, n) {
        scanf("%lld%lld%lld", &a, &b, &p);
        if (p >= 20) {
            printf("%lld\n", (ll) a * (ll) b);
            continue;
        }
        ll ans = 0;
        ans = cal(a, b);
        printf("%lld\n", ans);
    }

    return 0;
}