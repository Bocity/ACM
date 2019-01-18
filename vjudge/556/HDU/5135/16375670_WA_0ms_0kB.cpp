#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n) -1; i >= x; --i)
#define endl "\n"
#define DE puts("----------")
#define CASE(i, ans) cout << "Case #" << (i) << ": " << (ans) << "\n"
#define lowbit(x) ((x) & (-(x)))
#define sqr(x) ((x) * (x))
#define eps 1e-9
#define PI acos(-1.0)
#define MOD 1000000007
using namespace std;
typedef long long ll;
const int maxn = 10005;
ll n, m, k;
const long long mod = 1000000007;
double ans;
double s[maxn];
double calc(double x, double y, double z) {
    double p = (x + y + z) / 2;
    return sqrt(p * (p - x) * (p - y) * (p - z));
}
bool vis[maxn];
int main() {
    while (cin >> n && n) {
        REP(i, 0, n) {
            cin >> s[i];
        }
        memset(vis, 0, sizeof vis);
        ans = 0;
        sort(s, s + n);
        REP(i, 0, n) {
            REP(j, i + 1, n) {
                REP(k, j + 1, n) {
                    if (s[i] + s[j] > s[k] && s[k] + s[i] > s[j] && s[k] + s[j] > s[i] && !vis[i] && !vis[j] && !vis[k]) {
                        ans += calc(s[i], s[j], s[k]);
                        vis[i] = 1;
                        vis[j] = 1;
                        vis[k] = 1;
                    }
                }
            }
        }
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}
