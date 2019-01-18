
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
long long MOD = 1000000007;
ll x, y, a[1005], b[1005], sum[1005], f[1005], sum2[1005];
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
            // for (int k = 0; k <= y; k++) cout << sum[k];
            for (int j = 1; j <= y; j++) {
                if (a[i] == b[j]) {
                    // cout << "f[i]=" << f[i] << " " << j << endl;
                    f[i] = (sum[j - 1] + 1 + f[i]) % MOD;
                    // cout << f[i] << endl;
                    sum2[j]++;
                } else
                    sum2[j] = sum2[j - 1] % MOD;
            }
            for (int j = 1; j <= y; j++) sum[j] = sum2[j];
            // cout << "\n";
        }
        cout << f[x] % MOD << "\n";
    }

    return 0;
}