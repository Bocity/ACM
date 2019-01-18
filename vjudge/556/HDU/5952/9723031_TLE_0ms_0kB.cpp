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
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 200;
int n, m, ss;
vector<int> edges[110];
vector<int> points;
ll dfs(int s) {
    ll ret = 0;
    int vi[101];
    mems(vi, 0);
    for (auto p : points) {
        for (auto to : edges[p]) {
            vi[to]++;
        }
    }
    if (s < ss - 1) REP(i, 1, 101) {
            if (vi[i] == s) {
                points.push_back(i);
                ret += dfs(s + 1);
                points.pop_back();
            }
        }
    else
        REP(i, 1, 101) {
            if (vi[i] == s) ret++;
        }
    return ret;
}
ll f[20];
int main() {
    ios::sync_with_stdio(false);
    int t, u, v;
    cin >> t;
    f[0] = 1;
    REP(i, 1, 12) f[i] = f[i - 1] * i;
    while (t--) {
        cin >> n >> m >> ss;
        REP(i, 0, n + 1) edges[i].clear();
        REP(i, 0, m) {
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        ll ans = 0;
        REP(i, 1, n + 1) {
            points.clear();
            points.push_back(i);
            ans += dfs(1);
        }
        cout << (ans / f[ss]) << endl;
    }
}