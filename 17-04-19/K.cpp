
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
long long MOD = 1000000007;
ll x, y, a[1005], b[1005], f[1005][1005], sum[1005][1005], ans;
int main() {
    while (cin >> x >> y) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(sum, 0, sizeof(sum));
        memset(f, 0, sizeof(f));
        ans = 0;
        for (int i = 1; i <= x; i++) cin >> a[i];
        for (int j = 1; j <= y; j++) cin >> b[j];
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                if (a[i] == b[j]) {
                    f[i][j] = (sum[i - 1][j - 1] + 1) % MOD;
                    ans = (ans + f[i][j]) % MOD;
                }
                sum[i][j] = (((sum[i][j - 1] + sum[i - 1][j]) % MOD + f[i][j]) % MOD - sum[i - 1][j - 1] + MOD) % MOD;
            }
        }
        cout << ans;
    }

    return 0;
}