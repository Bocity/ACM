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
const int M = 10005;
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
ll ss, tt, ans, l, n, m;
int u[M], v[M], w[M];
vector<int> ze;
ll fuck(ll x) {
    for (auto i : ze) {
        w[i] = 1 + min(x, (ll)(1e9));
        x -= w[i] - 1;
    }
    solver.init(ss);
    for (int i = 0; i < m; i++) {
        solver.addarc(u[i], v[i], w[i]);
    }
    solver.go();
    return solver.dis[tt];
}
int main() {
    ios::sync_with_stdio(false);
    int s, t, c, cnt;
    while (cin >> n >> m >> l >> ss >> tt) {
        cnt = 0;
        ze.clear();
        for (int i = 0; i < m; i++) {
            cin >> s >> t >> c;
            u[cnt] = s, v[cnt] = t, w[cnt] = c;
            if (!w[cnt]) ze.push_back(cnt);
            cnt++;
        }
        ll right = (ll) 1e9 * cnt, left = 0;
        if (fuck(0) > l || fuck(right) < l) {
            cout << "NO" << endl;
            continue;
        }
        while (left < right) {
            ll mid = (left + right) >> 1;
            ll temp = fuck(mid);
            if (temp == l) break;
            if (temp > l) {
                right = mid;
            } else {
                left = mid;
            }
        }
        cout << "YES" << endl;
        for (int i = 0; i < m; i++) {
            cout << u[i] << " " << v[i] << " " << w[i] << endl;
        }
    }
    return 0;
}