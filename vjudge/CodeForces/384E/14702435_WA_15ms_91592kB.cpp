#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 2e5 + 1;
int v[N][100], cnt[N];
int seg[N << 2];
int naive[N << 2];
int dfn[N][2], stamp;
int dep[N];
int chg[N << 2];
void dfs(int now, int pre, int d) {
    dfn[now][0] = ++stamp;
    dep[stamp] = d;
    for (int i = cnt[now] - 1; i >= 0; i--)
        if (v[now][i] != pre) dfs(v[now][i], now, -d);
    dfn[now][1] = stamp;
}
void pushup(int rt) {
    naive[rt] = naive[rt << 1] + naive[rt << 1 | 1];
}
void pushdown(int rt, int fuck) {
    if (seg[rt] != 0) {
        seg[rt << 1] = seg[rt];
        seg[rt << 1 | 1] = seg[rt];
        seg[rt] = 0;
    }
}
void build(int l, int r, int rt) {
    if (l == r) {
        seg[rt] = 0;
        naive[rt] = dep[l];
        // cout << l << " " << naive[rt] << endl;
        return;
    }
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    pushup(rt);
}
void update(int l, int r, int rt, int L, int R, int fuck) {
    if (L <= l && r <= R && r - l + 1 == abs(naive[rt])) {
        seg[rt] += fuck * (naive[rt] > 0 ? 1 : -1);
        return;
    }
    int m = (l + r) >> 1;
    pushdown(rt, r - l + 1);
    if (L <= m) update(l, m, rt << 1, L, R, fuck);
    if (m < R) update(m + 1, r, rt << 1 | 1, L, R, fuck);
    pushup(rt);
}
int query(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R && l == r) {
        return seg[rt];
    }
    int m = (l + r) >> 1;
    pushdown(rt, r - l + 1);
    int ans = 0;
    if (L <= m) ans += query(l, m, rt << 1, L, R);
    if (m < R) ans += query(m + 1, r, rt << 1 | 1, L, R);
    pushup(rt);
    return ans;
}
int a[N];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 1; i < n; i++) {
        int p1, p2;
        scanf("%d%d", &p1, &p2);
        v[p1][cnt[p1]++] = p2;
        v[p2][cnt[p2]++] = p1;
    }
    dfs(1, 0, 1);
    build(1, n, 1);
    for (int i = 0; i < k; i++) {
        int val, tp;
        scanf("%d", &tp);
        if (tp == 2) {
            scanf("%d", &val);
            printf("%d\n", a[val] + query(1, n, 1, dfn[val][0], dfn[val][0]));
        } else {
            scanf("%d%d", &val, &tp);
            if (dep[dfn[val][0]] == 1) {
                update(1, n, 1, dfn[val][0], dfn[val][1], tp);
            } else {
                update(1, n, 1, dfn[val][0], dfn[val][1], -tp);
            }
        }
    }
    return 0;
}