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
const int maxn = 2000;
const double eps = 1e-7;
struct Edge {
    int from, to, cap, flow;
    ll cost;                               //@type
    Edge(int u, int v, int c, int f, ll w) //@type
        : from(u)
        , to(v)
        , cap(c)
        , flow(f)
        , cost(w) {}
};
struct MCMF {
    int n, m;
    vector<Edge> edges;
    vector<int> G[2 * maxn];
    int inq[2 * maxn];
    ll d[2 * maxn]; //@type
    int p[2 * maxn];
    int a[2 * maxn];

    void init(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from, int to, int cap, ll cost) { //@type
        edges.push_back(Edge(from, to, cap, 0, cost));
        edges.push_back(Edge(to, from, 0, 0, -cost));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool BellmanFord(int s, int t, int &flow, ll &cost) { //@type
        for (int i = 0; i < n; i++) d[i] = INF;           //@type
        memset(inq, 0, sizeof(inq));
        d[s] = 0;
        inq[s] = 1;
        p[s] = 0;
        a[s] = INF;

        queue<int> Q;
        Q.push(s);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            inq[u] = 0;
            for (int i = 0; i < G[u].size(); ++i) {
                Edge &e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost) { // eps to avoid TLE
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to]) {
                        Q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if (d[t] == INF) return false;
        flow += a[t];
        cost += d[t] * a[t];
        for (int u = t; u != s; u = edges[p[u]].from) {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
        }
        return true;
    }
    // 需保证无负环
    int MincostMaxflow(int s, int t, ll &cost) { //@type
        int flow = 0;
        cost = 0;
        while (BellmanFord(s, t, flow, cost))
            ;
        return flow;
    }
};
int n, m;
MCMF fuck;
void solve() {
    int x, y, c;
    fuck.init(3 * n + 1); // 0 - n
    REP(i, 0, m) {
        cin >> x >> y >> c;
        fuck.AddEdge(x + n, y, 1, c);
    }
    REP(i, 2, n) {
        fuck.AddEdge(i, i + n, 1, 0);
    }
    fuck.AddEdge(1, 1 + n, 2, 0);
    fuck.AddEdge(n, n + n, 2, 0);
    ll ans = 0; //@type
    fuck.MincostMaxflow(1, n + n, ans);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m) solve();
    return 0;
}