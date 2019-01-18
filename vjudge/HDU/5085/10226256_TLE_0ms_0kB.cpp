#include <bits/stdc++.h>
#define REP(i, x, n) for (long long i = (x); i < (n); i++)
#define endl "\n"
#define maxn 100000
#define N 1500015
#define MOD 998244353
#define mems(a, x) memset(a, (x), sizeof a)
typedef long long ll;
using namespace std;
ll a, b, k, S, ans;
long long f[100005];
int main() {
    ios::sync_with_stdio(0);
    while (cin >> a >> b >> k >> S) {
        memset(f, 0, sizeof f);
        ans = 0;
        REP(i, 0, 100000) {
            ll p = i;
            while (p != 0) {
                f[i] += pow(p % 10, k);
                p /= 10;
            }
        }

        if (b < 100000) {
            REP(i, a, b + 1) {
                if (f[i] == S) ans++;
            }
            cout << ans << endl;
        } else {
            REP(i, a, 100000) {
                if (f[i] == S) ans++;
            }
            sort(f, f + 100000);
            REP(i, 0, 10000) {
                if (i != 0 && i % 10 == 0 && i <= b / 100000) {
                    ll anss = S - f[i];
                    ll pos = lower_bound(f, f + 100000, anss) - f;
                    ll pos2 = upper_bound(f, f + 100000, anss) - f;
                    ans += pos2 - pos;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}