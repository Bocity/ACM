#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); i++)
#define endl "\n"
#define mems(a, x) memset(a, (x), sizeof a)
typedef long long ll;
using namespace std;
ll u, v, c[200005], kcase, len, ans = 0, s;
ll counts, n;
int vis[200005];
int viss[200005];
int size[200005];
int head[200005];
struct edge {
    int next, to;
} e[400005];
void addedge(int u, int v) {
    e[len].to = v;
    e[len].next = head[u];
    head[u] = len++;
}

void dfssize(int rt, int fa) {
    size[rt] = 1;
    for (int i = head[rt]; i != -1; i = e[i].next) {
        int v = e[i].to;
        if (v != fa) {
            dfssize(v, rt);
            size[rt] += size[v];
        }
    }
    return;
}
void dfsans(int rt, int fa) {
    vis[c[rt]]++;
    ll pre = vis[c[rt]];
    for (int i = head[rt]; i != -1; i = e[i].next) {
        int v = e[i].to;
        if (v != fa) {
            dfsans(v, rt);
            ll ct = size[v] - vis[c[rt]] + pre;
            // cout << ct << "-" << size[v] << "-" << vis[c[u]] << "-" << pre << endl;
            s += ((ct * (ct - 1)) >> 1);
            vis[c[rt]] += ct;
            pre = vis[c[rt]];
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    while (cin >> n) {
        mems(vis, 0);
        mems(viss, 0);
        mems(size, 0);
        mems(head, -1);
        len = 0;
        s = 0;
        ans = 0;
        counts = 0;
        REP(i, 1, n + 1) {
            cin >> c[i];
            if (!viss[c[i]]) {
                counts++;
            }
            viss[c[i]] = true;
        }
        ans = (counts * n * (n - 1)) >> 1;
        // cout << "--" << ans << endl;
        REP(i, 0, n - 1) {
            cin >> u >> v;
            addedge(u, v);
            addedge(v, u);
        }
        dfssize(1, 0);
        dfsans(1, 0);
        // cout << s << endl;
        // REP(i, 1, n + 1) {
        //     cout << vis[i] << " ";
        // }
        ans -= s;
        REP(i, 1, n + 1) {
            if (viss[i]) {
                ll ct = n - vis[i];
                ans -= (ct * (ct - 1) >> 1);
            }
        }
        cout << "Case #" << ++kcase << ": " << ans << endl;
    }
    return 0;
}