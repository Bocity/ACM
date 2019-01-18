#include <bits/stdc++.h>
#define N 100005
#define dls 300
#define endl "\n"
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll inv[N]{0};
void getInv(int n, int mod = MOD) {
    inv[1] = 1;
    for (int i = 2; i <= n; i++) inv[i] = inv[mod % i] * (mod - mod / i) % mod;
}
ll C[1005][1005]{0};
void getCom(int n) {
    for (int i = 0; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            if (i != 0) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}
ll sum[1005][N]{0};
void getSum() {
    for (int i = 0; i <= 1e5; ++i) {
        sum[0][i] = 1;
    }
    for (int i = 1; i <= 100; ++i) {
        ll pre = 1;
        sum[i][0] = 1;
        ll cur = i * 1000;
        for (int j = 1; j <= 1e5; ++j) {
            if (j > cur)
                sum[i][j] = sum[i][j - 1];
            else {
                pre = pre * (cur - j + 1) % MOD * inv[j] % MOD;
                sum[i][j] = (sum[i][j - 1] + pre) % MOD;
            }
        }
    }
}
ll ans = 0;
int main() {
    ios::sync_with_stdio(0);
    int t;
    getInv(N - 1);
    getCom(1000);
    getSum();
    cin >> t;
    int n, m;
    while (t--) {
        cin >> n >> m;
        int wdh = n % 1000;
        ans = 0;
        for (int i = m; i >= m - wdh; --i) {
            ans = (ans + sum[(n - wdh) / 1000][i] * C[wdh][m - i]) % MOD;
        }
        cout << ans << endl;
    }
}
