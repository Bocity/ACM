#include <bits/stdc++.h>
#define REP(i, x, n) for (long long i = (x); i < (n); i++)
#define PER(i, x, n) for (long long i = (n); i >= (x); i--)
#define endl "\n"
#define N 50015
#define MOD 998244353
#define mems(a, x) memset(a, (x), sizeof a)
using namespace std;
typedef long long ll;
const int maxn = 10000;
typedef bitset<10005> Bitset;
int gra[2][maxn << 1];
int head[maxn << 1];
bool vis[maxn << 1];
int ans;
Bitset aa;
struct EDAE {
    int to, next, w;
} edge[200005];
int e, ec;
void add(int a, int b) {
    e++;
    edge[e].to = b;
    edge[e].next = head[a];
    head[a] = e;
}
void dfs(int rt, int col) {
    gra[col][ec]++;
    vis[rt] = true;
    for (int i = head[rt]; i; i = edge[i].next) {
        int t = edge[i].to;
        if (!vis[t]) {
            dfs(t, col ^ 1);
        }
    }
}
void stay() {
    mems(vis, 0);
    int n, m, temp;
    e = 0, ec = 0, ans = 0;
    cin >> n >> m;
    REP(i, 0, n + 1) {
        head[i] = 0;
        vis[i] = 0;
    }
    REP(i, 0, m) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }

    REP(i, 1, n + 1) {
        if (!vis[i]) {
            gra[0][ec] = gra[1][ec] = 0;
            dfs(i, 0);
            ec++;
        }
    }
    aa.set(0);
    REP(i, 0, ec) {
        aa = (aa << gra[0][i]) | (aa << gra[1][i]);
    }
    REP(i, 0, n) {
        if (aa.test(i)) {
            int temp = i * (n - i) - m;
            ans = max(temp, ans);
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) stay();

    return 0;
}