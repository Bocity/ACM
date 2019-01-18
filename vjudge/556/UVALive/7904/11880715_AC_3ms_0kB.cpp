#include <bits/stdc++.h>

using namespace std;
const long long mod = 1e9 + 7;
const int N = 400000;
typedef long long ll;

long long quickPow(long long a, long long p, long long mod) {
    long long ret = 1LL;
    while (p) {
        if (p & 1) {
            ret = ret * a % mod;
        }
        p >>= 1;
        a = a * a % mod;
    }
    return ret;
}

int main() {
    int T, cas = 1;
    for (scanf("%d", &T); T--;) {
        ll n, m, k;
        scanf("%lld %lld %lld", &n, &m, &k);
        ll ans = quickPow(k, n * m, mod);
        ll tt = 0LL;
        for (ll i = 2; i <= k; ++i) {
            tt = (tt + quickPow(i - 1, n + m - 2, mod) * quickPow(k, n * m - n - m + 1, mod) % mod) % mod;
        }
        tt = (tt * n % mod) * m % mod;
        printf("Case #%d: %lld\n", cas++, (tt + ans) % mod);
    }
}