#include <bits/stdc++.h>
#define N 100005
#define endl "\n"
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll sum[400][N]{0};
ll C[400][400]{0};
ll inv[N]{0};
void getInv(int n, int mod = MOD) {
    inv[1] = 1;
    for (int i = 2; i <= n; i++) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
}

void getCom(int n) {
    for (int i = 0; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            if (i != 0) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

void getSum() {
    // memset(sum, 0 , sizeof sum);
    for (int i = 0; i <= 100000; ++i) {
        sum[0][i] = 1;
    }
    for (int i = 1; i <= 317; ++i) {
        ll pre = 1;
        sum[i][0] = 1;
        ll cur = i * 317;
        for (int j = 1; j <= 100000; ++j) {
            if (j > cur)
                sum[i][j] = sum[i][j - 1];
            else {
                pre = pre * (cur - j + 1) % MOD * inv[j] % MOD;
                sum[i][j] = (sum[i][j - 1] + pre) % MOD;
            }
        }
    }
}
// ll ahfkasdh = 0;
int main() {
    int t;
    getInv(N - 1);
    getCom(317);
    getSum();
    scanf("%d", &t);
    int n, m;
    while (t--) {
        scanf("%d%d", &n, &m);
        int wdh = n % 317;
        ll ans = 0;
        // cout << wdh << " " << (n - wdh) / 317 << endl;
        for (int i = m; i >= max(m - wdh, 0); --i) {
            ans = (ans + sum[(n - wdh) / 317][i] * C[wdh][m - i]) % MOD;
        }
        printf("%lld\n", ans);
    }
}