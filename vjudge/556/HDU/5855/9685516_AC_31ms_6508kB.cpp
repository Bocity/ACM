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
typedef pair<ll, ll> pii;
const int MOD = 1e9 + 7;
const ll INF = 1e15;
const int maxn = 100000;
const int maxm = 2500000;
// 点与边
struct Edge {
    int from, to;
    ll cap, flow;
};
struct ISAP {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn]; // 邻接表，G[i][j]表示结点i的第j条边在e数组中的序号
    bool vis[maxn];      // BFS使用
    bool vi[maxn];       // DFS使用
    int d[maxn];         // 从起点到i的距离
    int cur[maxn];       // 当前弧指针
    int p[maxn];         // 可增广路上的上一条弧
    int num[maxn];       // 距离标号计数

    void AddEdge(int from, int to, ll cap) {
        edges.push_back((Edge){from, to, cap, 0});
        edges.push_back((Edge){to, from, 0, 0});
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    bool BFS() {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(t);
        vis[t] = 1;
        d[t] = 0;
        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for (int i = 0; i < G[x].size(); i++) {
                Edge &e = edges[G[x][i] ^ 1];
                if (!vis[e.from] && e.cap > e.flow) {
                    vis[e.from] = 1;
                    d[e.from] = d[x] + 1;
                    Q.push(e.from);
                }
            }
        }
        return vis[s];
    }

    void ClearAll(int n) {
        this->n = n;
        for (int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }

    void ClearFlow() {
        for (int i = 0; i < m; i++) {
            edges[i].flow = 0;
        }
    }

    void print() {
        for (int i = 0; i < m; i += 2) {
            cout << edges[i].from << " -> " << edges[i].to << " = " << edges[i].cap << endl;
        }
    }

    ll Augment() {
        int x = t;
        ll a = INF;
        while (x != s) {
            Edge &e = edges[p[x]];
            a = min(a, e.cap - e.flow);
            x = edges[p[x]].from;
        }
        x = t;
        while (x != s) {
            edges[p[x]].flow += a;
            edges[p[x] ^ 1].flow -= a;
            x = edges[p[x]].from;
        }
        return a;
    }

    ll Maxflow(int s, int t) {
        this->s = s;
        this->t = t;
        ll flow = 0;
        BFS();
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; i++) num[d[i]]++;
        int x = s;
        memset(cur, 0, sizeof(cur));
        while (d[s] < n) {
            if (x == t) {
                flow += Augment();
                x = s;
            }
            int ok = 0;
            for (int i = cur[x]; i < G[x].size(); i++) {
                Edge &e = edges[G[x][i]];
                if (e.cap > e.flow && d[x] == d[e.to] + 1) { // Advance
                    ok = 1;
                    p[e.to] = G[x][i];
                    cur[x] = i; // 注意
                    x = e.to;
                    break;
                }
            }
            if (!ok) {         // Retreat
                int m = n - 1; // 初值注意
                for (int i = 0; i < G[x].size(); i++) {
                    Edge &e = edges[G[x][i]];
                    if (e.cap > e.flow) m = min(m, d[e.to]);
                }
                if (--num[d[x]] == 0) break;
                num[d[x] = m + 1]++;
                cur[x] = 0; // 注意
                if (x != s) x = edges[p[x]].from;
            }
        }
        return flow;
    }
} fuck;
ll pro[1000];
pii a[1000];
vector<pii> v;
vector<int> arc[1000];
bool vis[1000];
int main() {
#ifdef FUCK
#endif
    ios::sync_with_stdio(false);
    int n, m, p, cas = 1, c, num, t;
    ll l;
    cin >> t;
    while (t--) {
        cin >> n >> m >> l;
        fuck.ClearAll(n + m + 2);
        ll ans = 0, ans_ = 0;
        int s = 0, t = n + m + 1;
        v.clear();
        v.push_back(pii(0, 0));
        REP(i, 1, n + 1) {
            cin >> p >> c;
            v.push_back(pii(c, p));
        }
        REP(i, 1, m + 1) {
            a[i].first = 0;
            a[i].second = i;
        }
        REP(i, 1, m + 1) {
            arc[i].clear();
            cin >> pro[i] >> num;
            REP(j, 0, num) {
                cin >> p;
                arc[i].push_back(p);
                a[i].first = max(a[i].first, v[p].first);
            }
        }
        sort(a + 1, a + m + 1);
        mems(vis, false);
        ll day = 0;
        REP(i, 1, m + 1) {
            day = max(day, a[i].first);
            REP(j, i, m + 1) {
                if (a[j].first == day) {
                    int index = a[j].second;
                    fuck.AddEdge(s, index, pro[index]);
                    ans_ += pro[index];
                    for (auto k : arc[index]) {
                        if (!vis[k]) {
                            fuck.AddEdge(index, k + m, INF);
                            fuck.AddEdge(k + m, t, v[k].second);
                            vis[k] = true;
                        } else {
                            fuck.AddEdge(index, k + m, INF);
                        }
                    }
                } else {
                    i = j - 1;
                    ans = ans_;
                    ans -= fuck.Maxflow(s, t);
                    fuck.ClearFlow();
                    if (ans >= l) goto exit;
                    break;
                }
                i = j;
            }
        }
        ans = ans_;
        ans -= fuck.Maxflow(s, t);
        if (ans >= l) {
        exit:
            cout << "Case #" << cas++ << ": " << day << " " << ans << endl;
        } else {
            cout << "Case #" << cas++ << ": impossible" << endl;
        }
    }
    return 0;
}