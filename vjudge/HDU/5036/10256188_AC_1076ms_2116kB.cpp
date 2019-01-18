#include <bits/stdc++.h>
#define REP(i, x, n) for (long long i = (x); i < (n); i++)
#define PER(i, x, n) for (long long i = (n); i >= (x); i--)
#define endl "\n"
#define maxn 100000
#define N 50015
#define MOD 998244353
#define mems(a, x) memset(a, (x), sizeof a)
typedef long long ll;
using namespace std;
double ans;
int n, m, q, t, k, a[N], b[N], maxk, key, p;
bitset<1005> aa[1005];
int main() {
    ios::sync_with_stdio(0);
    cin >> t;
    REP(cas, 0, t) {
        ans = 0;
        cin >> n;
        REP(i, 0, n) {
            aa[i].reset();
            aa[i].set(i);
        }
        REP(i, 0, n) {
            cin >> p;
            REP(q, 0, p) {
                cin >> key;
                aa[i].set(key - 1);
            }
        }
        REP(j, 0, n) {
            REP(i, 0, n) {
                if (aa[i].test(j)) {
                    aa[i] |= aa[j];
                }
            }
        }
        REP(i, 0, n) {
            ll c = 0;
            REP(j, 0, n) {
                if (aa[j].test(i)) {
                    c++;
                }
            }
            ans += 1.0 / c;
        }
        cout << "Case #" << cas + 1 << ": " << fixed << setprecision(5) << ans << endl;
    }
    return 0;
}