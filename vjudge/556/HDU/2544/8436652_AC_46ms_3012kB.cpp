#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 2005;
const int M = 60005;

struct arc {
    int x, f, next;
};
struct dinic {
    int pre[N], mcnt, s, t;
    arc e[M];
    void init() {
        mcnt = 0;
        memset(pre, -1, sizeof pre);
    }
    void addarc(int x, int y, int z) {
        e[mcnt] = (arc){y, z, pre[x]}, pre[x] = mcnt++;
        e[mcnt] = (arc){x, 0, pre[y]}, pre[y] = mcnt++;
    }
    int d[N], cur[N], q[N];
    bool BFS() {
        memset(d, -1, sizeof(d));
        int top = 0, bot = -1;
        q[++bot] = t, d[t] = 1;
        while (top != bot + 1) {
            int x = q[top++];
            for (int i = pre[x]; ~i; i = e[i].next) {
                int y = e[i].x;
                if (!~d[y] && e[i ^ 1].f) {
                    d[y] = d[x] + 1, q[++bot] = y;
                    if (y == s) return true;
                }
            }
        }
        return false;
    }
    int DFS(int x, int flow = 1 << 30) {
        if (x == t || !flow) return flow;
        int sum = 0, u;
        for (int &i = cur[x]; ~i; i = e[i].next) {
            int y = e[i].x;
            if (d[x] == d[y] + 1 && (u = DFS(y, min(flow, e[i].f)))) {
                e[i].f -= u, e[i ^ 1].f += u;
                sum += u, flow -= u;
                if (!flow) break;
            }
        }
        if (!sum) d[x] = -1;
        return sum;
    }
    int go() {
        int ans = 0;
        while (BFS()) {
            memcpy(cur, pre, sizeof(cur));
            ans += DFS(s);
        }
        return ans;
    }
};
struct spfa {
    int pre[N], mcnt, s, dis[N], vis[N];
    arc e[2 * M];
    void init(int i) {
        mems(pre, -1);
        s = i;
    }
    void addarc(int x, int y, int z) {
        e[mcnt] = (arc){y, z, pre[x]}, pre[x] = mcnt++;
        e[mcnt] = (arc){x, z, pre[y]}, pre[y] = mcnt++;
    }
    void go() {
        queue<int> q;
        mems(dis, 0x3f);
        mems(vis, 0);
        dis[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = 0;
            for (int i = pre[u]; ~i; i = e[i].next) {
                int v = e[i].x, c = e[i].f;
                if (dis[v] > dis[u] + c) {
                    dis[v] = dis[u] + c;
                    if (!vis[v]) vis[v] = 1, q.push(v);
                }
            }
        }
    }
};
int main() {
    int n, m;
    int x, y, c;
    while (cin >> n >> m && n + m) {
        spfa fuck;
        fuck.init(1);
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> c;
            fuck.addarc(x, y, c);
        }
        fuck.go();
        cout << fuck.dis[n] << endl;
    }
    return 0;
}