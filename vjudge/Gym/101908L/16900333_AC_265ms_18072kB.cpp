#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e5 + 10;
const int N = 1e5 + 10;
int n, m, fa[maxn], dep[maxn], size[maxn];
int root = 1, tot, pos[maxn], son[maxn], tid[maxn], top[maxn];
ll val[maxn];
vector<int> G[maxn];
struct Pair {
    int v1, v2;
    Pair() {}
    Pair(int _v1, int _v2) {
        v1 = _v1, v2 = _v2;
    }
};
Pair operator+(Pair a, Pair b) {
    return Pair((a.v1 + b.v1) % 2019, (a.v2 + b.v2) % 2019);
}
void dfs1(int x, int father, int depth) {
    fa[x] = father, dep[x] = depth;
    size[x] = 1;
    int max_size = 0;
    for (int i = 0; i < G[x].size(); i++) {
        if (G[x][i] == father) continue;
        dfs1(G[x][i], x, depth + 1);
        size[x] += size[G[x][i]];
        if (size[G[x][i]] > max_size) {
            max_size = size[G[x][i]];
            son[x] = G[x][i];
        }
    }
}

void dfs2(int x, int root, int father) {
    tid[x] = ++tot, pos[tot] = x, top[x] = root;
    if (son[x]) {
        if (son[x] != father) dfs2(son[x], root, x);
    }
    for (int i = 0; i < G[x].size(); i++) {
        if (G[x][i] == father) continue;
        if (G[x][i] != son[x]) {
            dfs2(G[x][i], G[x][i], x);
        }
    }
}

#define LSON l, m, rt << 1
#define RSON m + 1, r, rt << 1 | 1
#define lson rt << 1
#define rson rt << 1 | 1
ll sum[N << 2], add[N << 2];
// 更新答案
void Maintain(int rt) {
    sum[rt] = (sum[lson] + sum[rson]);
    return;
}
// 延时标记下传
void Pushdown(int rt, int m) {
    if (add[rt] != 0) { // 倍数变化 add[rt] != 1
        add[rt << 1] += add[rt];
        add[rt << 1 | 1] += add[rt];
        sum[rt << 1] = (sum[rt << 1] + add[rt] * (m - (m >> 1)));
        sum[rt << 1 | 1] = (sum[rt << 1 | 1] + add[rt] * (m >> 1));
        add[rt] = 0;
    }
}
void build(int l, int r, int rt = 1) {
    add[rt] = 0; // 倍数变化更改为1
    if (l == r) {
        // cout << val[pos[l]] <<  endl;
        sum[rt] = 0;
        // cout <<sum3[rt] << endl;
        return;
    }
    int m = (l + r) >> 1;
    build(LSON);
    build(RSON);
    Maintain(rt);
    return;
}
void update(int L, int R, int c, int l, int r, int rt = 1) {
    if (L > r || R < l) return;
    if (L <= l && r <= R) {
        sum[rt] = (sum[rt] + c * (r - l + 1));
        add[rt] += c;
        return;
    }
    Pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, c, LSON);
    if (m < R) update(L, R, c, RSON);
    Maintain(rt);
    return;
}
int query(int L, int R, int l, int r, int rt = 1) {
    if (L > r || R < l) return 0;
    if (L <= l && r <= R) {
        return sum[rt];
    }
    Pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    return query(L, R, LSON) + query(L, R, RSON);
}
// int lca(int u, int v) {
//     int res;
//     while (top[u] != top[v]) {
//         res = top[v];
//         v = fa[top[v]];
//     }
//     return u == v ? res : son[u];
// }

int lca(int x, int y) {
    int fx = top[x], fy = top[y];
    while (fx != fy) {
        if (dep[fx] > dep[fy])
            x = fa[fx], fx = top[x];
        else
            y = fa[fy], fy = top[y];
    }
    if (dep[x] >= dep[y]) return y;
    return x;
}
void solve_add(int u, int v, ll val) {
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) {
            swap(u, v);
        }
        update(tid[top[u]], tid[u], val, 1, n);
        u = fa[top[u]];
    }
    if (tid[u] > tid[v]) {
        swap(u, v);
    }
    update(tid[u], tid[v], val, 1, n);
}
int solve_query(int u, int v) {
    int sum = 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] < dep[top[v]]) {
            swap(u, v);
        }
        sum = sum + query(tid[top[u]], tid[u], 1, n);
        u = fa[top[u]];
    }
    if (tid[u] > tid[v]) {
        swap(u, v);
    }
    sum = sum + query(tid[u], tid[v], 1, n);
    return sum;
}
int main() {
    int M;
    scanf("%d%d", &n, &M);
    root = 1;
    int u, v;
    for (int i = 2; i <= n; i++) {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    tot = 0;
    dfs1(root, 0, 0), dfs2(root, 0,0);
    build(1, n);
    while (M--) {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        solve_add(a, b, 1);
        printf("%d\n", solve_query(c, d));
        solve_add(a, b, -1);
    }
    return 0;
}