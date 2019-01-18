#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int mod = 1e9;

int n, m;
int a[500010], p;
int sum[32][500010];
ll qpow(ll n, ll m) {
    ll ans = 1;
    while (m) {
        if (m & 1) ans *= n;
        n *= n;
        m >>= 1;
        if (ans > 20001001000) return -1;
    }
    return ans;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= 31; i++) 
        {
            sum[i][0] = 0;
            for (int j = 1; j <= n; j++) sum[i][j] = (sum[i][j - 1] + a[j] / i) % mod;
        }
        ll ans = 0;
        for (int k = 1; k <= m; k++) {
            cin >> p;
            ll res = 0;
            for (int i = 1; i <= 31; i++) 
            {
                ll down = qpow(p, i - 1); 
                ll up = qpow(p, i);       
                if (down == -1) break;

                int l = 1, r = n + 1, mid;
                if (down != -1)
                    while (l < r) {
                        mid = (l + r) >> 1;
                        if (a[mid] > down)
                            r = mid;
                        else
                            l = mid + 1;
                    }
                int L = r;

                l = 1, r = n + 1;
                if (up != -1)
                    while (l < r) {
                        mid = (l + r) >> 1;
                        if (a[mid] > up)
                            r = mid;
                        else
                            l = mid + 1;
                    }
                int R = r - 1;
                if (L > n) break;
                if (L > R) continue;

                res = (res + sum[i][R] - sum[i][L - 1]) % mod;
                res = (res + mod) % mod;
            }
            ans = (ans + res * k % mod) % mod;
        }
        cout << ans << endl;
    }
}