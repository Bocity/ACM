#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
const int inf = 0x3f3f3f3f;
const int N = 25000;
const int M = 25000;
// 点与边

struct arc {
    int x, f, next;
};
struct dinic {
    int pre[N], mcnt, s, t;
    arc e[2 * M];
    void init(int n, int m) {
        mcnt = 0;
        memset(pre, -1, sizeof pre);
        s = n, t = m;
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
        fuck.init(s, d);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i + j) & 1) {
                    if (mp[i][j] == '.') {
                        fuck.addarc(s, f(i, j), inf);
                    } else if (mp[i][j] == 'D') {
                        fuck.addarc(f(i, j), d, inf);
                    }
                } else {
                    if (mp[i][j] == 'D') {
                        fuck.addarc(s, f(i, j), inf);
                    } else if (mp[i][j] == '.') {
                        fuck.addarc(f(i, j), d, inf);
                    }
                }
                for (int k = 0; k < 4; k++) {
                    int xx = i + x[k];
                    int yy = j + y[k];
                    if (cango(xx, yy)) {
                        ans++;
                        if (mp[i][j] == 'E' || mp[xx][yy] == 'E') {
                            fuck.addarc(f(i, j), f(xx, yy), 1);
                        } else if (mp[i][j] == '.' && mp[xx][yy] == '.') {
                            fuck.addarc(f(i, j), f(xx, yy), 1);
                        } else if (mp[i][j] == 'D' && mp[xx][yy] == 'D') {
                            fuck.addarc(f(i, j), f(xx, yy), 1);
                        }
                    }
                }
            }
        }
        cout << "Case " << cas << ": " << ans / 2 - fuck.go() << endl;
    }
}
