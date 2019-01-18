#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 2010;
vector<int> e[N];
vector<pii> ed;
int n, K;
ll dp[2010][55];
bool vis[2010];
void dfs(int pos) {
    vis[pos] = true;
    dp[pos][0] = dp[pos][1] = 0;
    for (auto &k : e[pos]) {
        int c = ed[k].second, to = ed[k].first;
        if (vis[to]) continue;
        dfs(to);
        REP(i, 0, K + 1) {
            REP(j, 0, i + 1) {
                if (dp[to][j] != INF && dp[pos][i - j] != INF) {
                    dp[pos][i] = min(dp[pos][i], dp[pos][i - j] + dp[to][j] + 2ll * c * j * (K - j));
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    int t, u, v, c;
    cin >> t;
    while (t--) {
        cin >> n >> K;
        REP(i, 0, n + 1) e[i].clear();
        ed.clear();
        int cnt = 0;
        REP(i, 0, n - 1) {
            cin >> u >> v >> c;
            ed.push_back(pii(v, c));
            e[u].push_back(cnt++);
            ed.push_back(pii(u, c));
            e[v].push_back(cnt++);
        }
        mems(dp, INF);
        mems(vis, 0);
        dfs(1);
        cout << dp[1][K] << endl;
    }
    return 0;
}