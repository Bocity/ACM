
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
long long MOD = 1000000007;
ll x, y, a[1005], b[1005], sum[1005], f[1005];
int main() {
    while (cin >> x >> y) {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(sum, 0, sizeof(sum));
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= x; i++) cin >> a[i];
        for (int j = 1; j <= y; j++) cin >> b[j];
        for (int i = 1; i <= x; i++) {
            f[i] = f[i - 1] % MOD;
            // cout << f[i] << endl;
            for (int j = 1; j <= y; j++) {
                // cout << "sum:" << sum[j];
                if (a[i] == b[j]) {
                    f[i] = (sum[j - 1] + 1 + f[i]) % MOD;
                    sum[j]++;
                } else
                    sum[j] = max(sum[j - 1], sum[j]) % MOD;
            }
            // cout << "\n";
        }
        cout << f[x] % MOD << "\n";
    }

    return 0;
}