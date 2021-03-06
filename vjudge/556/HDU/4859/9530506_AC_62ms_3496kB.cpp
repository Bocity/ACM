#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
const int INF = 0x3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int maxn = 25000;
const int maxm = 25000;
// 点与边
struct Edge {
    int from, to, cap, flow;
};

struct ISAP {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn]; // 邻接表，G[i][j]表示结点i的第j条边在e数组中的序号
    bool vis[maxn];      // BFS使用
    int d[maxn];         // 从起点到i的距离
    int cur[maxn];       // 当前弧指针
    int p[maxn];         // 可增广路上的上一条弧
    int num[maxn];       // 距离标号计数

    void AddEdge(int from, int to, int cap) {
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
        for (int i = 0; i < edges.size(); i++) edges[i].flow = 0;
    }

    int Augment() {
        int x = t, a = INF;
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

    int Maxflow(int s, int t) {
        this->s = s;
        this->t = t;
        int flow = 0;
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

    vector<int> Mincut() { // call this after maxflow
        BFS();
        vector<int> ans;
        for (int i = 0; i < edges.size(); i++) {
            Edge &e = edges[i];
            if (!vis[e.from] && vis[e.to] && e.cap > 0) ans.push_back(i);
        }
        return ans;
    }

    void Reduce() {
        for (int i = 0; i < edges.size(); i++) edges[i].cap -= edges[i].flow;
    }

    void print() {
        printf("Graph:\n");
        for (int i = 0; i < edges.size(); i++)
            printf("%d->%d, %d, %d\n", edges[i].from, edges[i].to, edges[i].cap, edges[i].flow);
    }
} fuck;
int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};
char mp[50][50];
int n, m;
bool cango(int x, int y) {
    return (x < n && x > -1 && y < m && y > -1);
}
int f(int x, int y) {
    return x * m + y + 1;
}
int main() {
    ios::sync_with_stdio(false);
    int t, ans;
    cin >> t;
    for (int cas = 1; cas <= t; cas++) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> mp[i][j];
            }
        }
        n += 2, m += 2;
        for (int i = 0; i < n; i++) {
            mp[i][0] = mp[i][m - 1] = 'D';
        }
        for (int i = 0; i < m; i++) {
            mp[0][i] = mp[n - 1][i] = 'D';
        }
        int s = 0, d = n * m + 2;
        fuck.ClearAll(d);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) & 1) {
                    if (mp[i][j] == '.') {
                        fuck.AddEdge(s, f(i, j), inf);
                    } else if (mp[i][j] == 'D') {
                        fuck.AddEdge(f(i, j), d, inf);
                    }
                } else {
                    if (mp[i][j] == 'D') {
                        fuck.AddEdge(s, f(i, j), inf);
                    } else if (mp[i][j] == '.') {
                        fuck.AddEdge(f(i, j), d, inf);
                    }
                }
                for (int k = 0; k < 4; k++) {
                    int xx = i + x[k];
                    int yy = j + y[k];
                    if (cango(xx, yy)) {
                        ans++;
                        if (mp[i][j] == 'E' || mp[xx][yy] == 'E') {
                            fuck.AddEdge(f(i, j), f(xx, yy), 1);
                        } else if (mp[i][j] == '.' && mp[xx][yy] == '.') {
                            fuck.AddEdge(f(i, j), f(xx, yy), 1);
                        } else if (mp[i][j] == 'D' && mp[xx][yy] == 'D') {
                            fuck.AddEdge(f(i, j), f(xx, yy), 1);
                        }
                    }
                }
            }
        }
        cout << "Case " << cas << ": " << ans / 2 - fuck.Maxflow(s, d) << endl;
    }
}
