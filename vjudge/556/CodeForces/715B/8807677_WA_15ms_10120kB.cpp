#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const int N = 1010;
const int M = 10000;
struct arc {
    int x, f, next;
};
struct spfa {
    int pre[N], mcnt, s, dis[N];
    bool vis[N];
    arc e[2 * M];
    void init(int i) {
        mems(pre, -1);
        mcnt = 0;
        s = i;
    }
    void addarc(int x, int y, int z) {
        e[mcnt] = (arc){y, z, pre[x]}, pre[x] = mcnt++;
        e[mcnt] = (arc){x, z, pre[y]}, pre[y] = mcnt++;
    }
    void go() {
        queue<int> q;
        mems(dis, 0x3f);
        mems(vis, false);
        dis[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = false;
            for (int i = pre[u]; ~i; i = e[i].next) {
                int v = e[i].x, c = e[i].f;
                if (dis[v] > dis[u] + c) {
                    dis[v] = dis[u] + c;
                    if (!vis[v]) vis[v] = true, q.push(v);
                }
            }
        }
    }
} solver;
vector<int> hs[N];
ll edges[N][N];
bool vis[N];
ll ss, tt, ans, l;
bool dfs(int pos, int cnt, int cost) {
    if (pos == tt) {
        if (cnt > l - cost)
            return false;
        else {
            ans = l - cost;
            return true;
        }
    }
    for (auto j : hs[pos]) {
        if (!vis[j]) {
            vis[j] = true;
            if (dfs(j, cnt + (edges[pos][j] == 0), cost + edges[pos][j])) {
                if (edges[pos][j] == 0) {
                    if (cnt == 0)
                        edges[pos][j] = edges[j][pos] = ans;
                    else {
                        edges[pos][j] = edges[j][pos] = 1;
                        ans--;
                    }
                }
                return true;
            }
            vis[j] = false;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    int n, m, s, t, c;
    while (cin >> n >> m >> l >> ss >> tt) {
        solver.init(ss);
        mems(vis, false);
        for (int i = 0; i < m; i++) {
            cin >> s >> t >> c;
            if (c) solver.addarc(s, t, c);
            hs[s].push_back(t);
            hs[t].push_back(s);
            edges[s][t] = edges[t][s] = c;
        }
        solver.go();
        bool fg = dfs(ss, 0, 0);
        if (solver.dis[tt] < l || !fg) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                for (auto j : hs[i]) {
                    if (j < i) cout << i << " " << j << " " << edges[i][j] << endl;
                }
            }
        }
    }
    return 0;
}