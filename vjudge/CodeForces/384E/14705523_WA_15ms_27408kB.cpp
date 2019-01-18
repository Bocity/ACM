#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int N = 2e5 + 1;
vector<int> e[N];
int s[N], seg[N << 2], num[N << 2], chg[N << 2], dfn[N][2], sgn[N] = {-1}, stamp;
void dfs(int now, int pre, int d) {
    dfn[now][0] = ++stamp;
    sgn[stamp] = d;
    for (int i = 0; i < e[now].size(); i++)
        if (e[now][i] != pre) dfs(e[now][i], now, -d);
    dfn[now][1] = stamp;
}
void pushdown(int rt, int l, int r) {
    if (chg[rt]) {
        chg[rt << 1] += chg[rt];
        chg[rt << 1 | 1] += chg[rt];
        chg[rt] = 0;
    }
}
void build(int l, int r, int rt) {
    if (l == r) {
        num[rt] = sgn[l];
        return;
    }
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    num[rt] = num[rt << 1] + num[rt << 1 | 1];
}
void update(int l, int r, int rt, int L, int R, int v) {
    if (L > l || r > R) return;
    if (L <= l && r <= R) {
        chg[rt] += v;
        return;
    }
    int m = l + r >> 1;
    pushdown(rt, l, r);
    if (L <= m) update(l, m, rt << 1, L, R, v);
    if (m < R) update(m + 1, r, rt << 1 | 1, L, R, v);
}
int query(int l, int r, int rt, int p) {
    if (l == r && r == p) return chg[rt] * num[rt];
    int m = l + r >> 1;
    pushdown(rt, l, r);
    int ans = 0;
    if (p <= m)
        ans = query(l, m, rt << 1, p);
    else
        ans = query(m + 1, r, rt << 1 | 1, p);
    return ans;
}
main() {
    ios::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i < n; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        e[tmp1].push_back(tmp2);
        e[tmp2].push_back(tmp1);
    }
    stamp = 0;
    dfs(1, 0, 1);
    build(1, n, 1);
    for (int i = 0; i < k; i++) {
        int op, tmp1, tmp2;
        cin >> op;
        if (op == 1) {
            cin >> tmp1 >> tmp2;
            update(1, n, 1, dfn[tmp1][0], dfn[tmp1][1], sgn[dfn[tmp1][0]] * tmp2);
        } else {
            cin >> tmp1;
            cout << s[dfn[tmp1][0]]  + query(1, n, 1, dfn[tmp1][0]) << endl;
        }
    }
    return 0;
}