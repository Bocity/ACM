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
#define INF 100000000
#define pii pair<int, int>
#define MOD 1000000007
using namespace std;
typedef long long ll;
const int maxn = 10005;
ll n, m, k;
vector<pii> q;
int vis[200][200];
int vis2[200][200];
int a, b, c;
int main() {
    while (cin >> n >> m && n && m) {
        for (int i = 1; i <= 100; ++i) {
            for (int j = 1; j <= 100; ++j) {
                vis[i][j] = INF;
                vis2[i][j] = INF;
            }
        }
        int ans = -1;
        REP(i, 0, m) {
            cin >> a >> b >> c;
            vis[a][b] = c;
            vis2[a][b] = c;
        }
        for (int p = 2; p < n; ++p) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    vis[i][j] = vis2[i][j];
                }
            }
            for (int k = 1; k <= n; ++k) {
                    // q.push_back(pii(k, vis[k][p]));
                    vis[k][p] = INF;
                    vis[p][k] = INF;
            }
            for (int k = 1; k <= n; ++k) {
                for (int i = k + 1; i <= n; ++i) {
                    for (int j = i + 1; j <= n; ++j) {
                        if (vis[i][j] > vis[i][k] + vis[k][j]) {
                            vis[i][j] = vis[i][k] + vis[k][j];
                        }
                    }
                }
            }
            // for (auto &x : q) {
            //     vis[x.first][p] = x.second;
            // }
            // q.clear();
        }
        // if (vis[i][j])
        ans = max(ans, vis[1][n]);
        if (ans == INF) {
            cout << "Inf" << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}
