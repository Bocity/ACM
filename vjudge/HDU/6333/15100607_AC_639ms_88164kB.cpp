#include <bits/stdc++.h>
#define N 100005
#define endl "\n"
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll sum[1005][N]{0};
ll C[1005][1005]{0};
ll inv[N]{0};
void getInv(int n, int mod = MOD) {
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
}

void getCom(int n) {
    C[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

void getSum() {
    for (int i = 0; i <= 100000; ++i) {
        sum[0][i] = 1;
    }
    ll pre, cur;
    for (register int i = 1; i <= 100; ++i) {
        pre = 1;
        sum[i][0] = 1;
        cur = i * 1000;
        for (register int j = 1; j <= 100000; ++j) {
            if (j > cur)
                sum[i][j] = sum[i][j - 1];
            else {
                pre = pre * (cur - j + 1) % MOD * inv[j] % MOD;
                sum[i][j] = (sum[i][j - 1] + pre) % MOD;
            }
        }
    }
}
int t;
int main() {
    getInv(N - 1);
    getCom(1000);
    getSum();
    scanf("%d", &t);
    int n, m, wdh, wdhnb;
    while (t--) {
        scanf("%d%d", &n, &m);
        wdh = n % 1000;
        ll ans = 0;
        wdhnb = (n - wdh) / 1000;
        // cout << wdh << " " << (n - wdh) / 317 << endl;
        int fuck = max(m - wdh, 0);
        for (int i = m; i >= fuck; --i) {
            ans = (ans + sum[wdhnb][i] * C[wdh][m - i]) % MOD;
        }
        printf("%lld\n", ans);
    }
}
