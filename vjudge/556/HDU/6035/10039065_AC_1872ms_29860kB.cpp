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
const int MAXN = 200100;
int cr[MAXN];
bool vis[MAXN];
vector<int> edge[MAXN];
map<int, int> cnt;
set<int> color;
ll ans = 0;
inline ll f(ll n) {
    return n * (n - 1) / 2ll;
}
int dfs(int u) {
    vis[u] = true;
    ll add = 0, ret = 1;
    for (auto &p : edge[u]) {
        if (vis[p]) continue;
        ll before = cnt[cr[u]];
        ll sz = dfs(p);
        ll gap = sz - (cnt[cr[u]] - before);
        ans += f(gap), add += gap, ret += sz;
    }
    cnt[cr[u]] += add + 1;
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    int cas = 1, n;
    while (cin >> n) {
        color.clear();
        REP(i, 1, n + 1) {
            cin >> cr[i];
            color.insert(cr[i]);
        }
        REP(i, 0, n + 1) edge[i].clear();
        int x, y;
        REP(i, 0, n - 1) {
            cin >> x >> y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        cnt.clear(), mems(vis, false), ans = 0;
        ll temp = dfs(1);
        for (auto it : cnt) {
            ans += f(n - it.second);
        }
        cout << "Case #" << cas++ << ": " << color.size() * f(n) - ans << endl;
    }
    return 0;
}