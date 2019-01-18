#include <bits/stdc++.h>
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
const int N = 100100;
const int M = 100100;
struct arc {
    int x, f, next;
};
struct Dijkstra {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int pre[N], mcnt, s, dis[N];
    arc e[2 * M];
    void init(int i) {
        mems(pre, -1);
        mcnt = 0;
        s = i;
    }
    void addarc(int x, int y, int z) {
        e[mcnt] = (arc){y, z, pre[x]}, pre[x] = mcnt++;
        // e[mcnt] = (arc){x, z, pre[y]}, pre[y] = mcnt++;
    }
    void go() {
        mems(dis, 0x3f);
        dis[s] = 0;
        pq.push(pii(0, s));
        while (!pq.empty()) {
            pii top = pq.top();
            pq.pop();
            int d = top.first, u = top.second;
            for (int i = pre[u]; ~i; i = e[i].next) {
                int v = e[i].x, c = e[i].f;
                if (dis[v] > dis[u] + c) {
                    dis[v] = dis[u] + c;
                    pq.push(pii(dis[v], v));
                }
            }
        }
    }
} solver;
int u[N], v[N], c[N], p[N];
int main() {
    ios::sync_with_stdio(false);
    int t, n, m, K, cas = 1;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        REP(i, 0, m) {
            cin >> u[i] >> v[i] >> c[i];
        }
        cin >> K;
        REP(i, 0, K) cin >> p[i];
        int ans = INF;
        REP(bi, 0, 20) {
            solver.init(0);
            REP(i, 0, m) solver.addarc(u[i], v[i], c[i]);
            REP(i, 0, K) if ((1 << bi) & p[i]) solver.addarc(0, p[i], 0);
            else solver.addarc(p[i], n + 1, 0);
            solver.go();
            ans = min(ans, solver.dis[n + 1]);
            solver.init(0);
            REP(i, 0, m) solver.addarc(u[i], v[i], c[i]);
            REP(i, 0, K) if (!((1 << bi) & p[i])) solver.addarc(0, p[i], 0);
            else solver.addarc(p[i], n + 1, 0);
            solver.go();
            ans = min(ans, solver.dis[n + 1]);
        }
        cout << "Case #" << cas++ << ": ";
        cout << ans << endl;
    }
    return 0;
}