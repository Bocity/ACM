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
#define pii pair<int, int>
#define MOD 1000000007
using namespace std;
typedef long long ll;
const int maxn = 10005;
ll n, m, k;
const ll INF = -1;
ll vis[200][200];
ll vis2[200][200];
ll a, b, c;
int main() {
   // cout << INF << endl;
    while (cin >> n >> m) {
        //cout << 0x3f3f3f3f << endl;;
        if (n == 0 && m == 0) break;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                vis[i][j] = INF;
                vis2[i][j] = INF;
            }
        }
        ll ans = INF;
        REP(i, 0, m) {
            cin >> a >> b >> c;
            vis[a][b] = c;
            vis[b][a] = c;
            vis2[a][b] = c;
            vis2[b][a] = c;
        }
        for (int p = 2; p < n; ++p) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    vis[i][j] = vis2[i][j];
                }
            }
            for (int k = 1; k <= n; ++k) {
                vis[k][p] = INF;
            }
            for (int k = 1; k <= n; ++k) {
                for (int i = 1; i <= n; ++i) {
                    for (int j = 1; j <= n; ++j) {
                        if (i == j || j == k || k == i) continue;
                        if (vis[i][k] == INF ||  vis[k][j] == INF) continue;
                        if (vis[i][j] > vis[i][k] + vis[k][j] || vis[i][j] == INF) {
                            vis[i][j] = vis[i][k] + vis[k][j];
                        }
                    }
                }
            }
        }
        ans = max(ans, vis[1][n]);
        if (ans == INF) {
            cout << "Inf" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
