#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 1;
vector<int> v[N << 1];
int seg[N << 1], dfn[N][2], stamp;
bool chg[N << 1];
void dfs(int x, int fa) {
    dfn[x][0] = ++stamp;
    int sz = v[x].size();
    for (int i = 0; i < v[x].size(); i++)
        if (v[x][i] != fa) dfs(v[x][i], x);
    dfn[x][1] = stamp;
}
void pushup(int rt) {
    seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}
void pushdown(int rt, int ln, int rn) {
    if (chg[rt]) {
        chg[rt] = 0;
        seg[rt << 1] = ln - seg[rt << 1];
        seg[rt << 1 | 1] = rn - seg[rt << 1 | 1];
        chg[rt << 1] = 1;
        chg[rt << 1 | 1] = 1;
    }
}
void update(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R) {
        seg[rt] = r - l + 1 - seg[rt];
        chg[rt] = 1;
        return;
    }
    int m = (l + r) >> 1;
    pushdown(rt, m - l + 1, r - m);
    if (L <= m) update(l, m, rt << 1, L, R);
    if (m < R) update(m + 1, r, rt << 1 | 1, L, R);
    pushup(rt);
}
int query(int l, int r, int rt, int L, int R) {
    if (L <= l && r <= R) return seg[rt];
    int m = (l + r) >> 1;
    pushdown(rt, m - l + 1, r - m + 1);
    int ans = 0;
    if (L <= m) ans += query(l, m, rt << 1, L, R);
    if (m < R) ans += query(m + 1, r, rt << 1 | 1, L, R);
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    int n, k;
    while (cin >> n >> k) {
        for (int i = 1; i <= n; i++) v[i].clear();
        for (int i = 2; i <= n; i++) {
            int tmp;
            cin >> tmp;
            v[tmp].push_back(i);
            v[i].push_back(tmp);
        }
        stamp = 0;
        dfs(1, 0);
        memset(seg, 0, sizeof(seg));
        memset(chg, 0, sizeof(chg));
        for (int i = 0; i < k; i++) {
            char ch;
            int val;
            cin >> ch >> val;
            if (ch == 'o')
                update(1, n, 1, dfn[val][0], dfn[val][1]);
            else
                cout << query(1, n, 1, dfn[val][0], dfn[val][1]) << endl;
        }
    }
    return 0;
}