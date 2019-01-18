#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = x; i < n; ++i)
#define PER(i, x, n) for (int i = (n - 1); i >= x; --i)
#define N 600010
#define ll long long
using namespace std;
int n, m, tot, fa[N], w[N], d[N], rt[N];
ll sum;
struct heap {
    int l, r, dis;
    ll v;
} tr[N];
inline int merge(int x, int y) {
    if (!x || !y) return x + y;
    if (tr[x].v < tr[y].v) swap(x, y);
    tr[x].r = merge(tr[x].r, y);
    if (tr[tr[x].l].dis < tr[tr[x].r].dis) swap(tr[x].l, tr[x].r);
    if (!tr[x].r)
        tr[x].dis = 0;
    else
        tr[x].dis = tr[tr[x].r].dis + 1;
    return x;
}
inline int pop(int x) {
    return merge(tr[x].l, tr[x].r);
}
int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    REP(i, 2, n + m + 1) {
        cin >> fa[i] >> w[i];
        sum += w[i];
        d[fa[i]]++;
    }
    PER(i, 2, n + m + 1) {
        ll r = 0, l = 0;
        if (i <= n) {
            while (--d[i]) rt[i] = pop(rt[i]);
            r = tr[rt[i]].v;
            rt[i] = pop(rt[i]);
            l = tr[rt[i]].v;
            rt[i] = pop(rt[i]);
        }
        tr[++tot].v = l + w[i];
        tr[++tot].v = r + w[i];
        rt[i] = merge(rt[i], merge(tot, tot - 1));
        rt[fa[i]] = merge(rt[fa[i]], rt[i]);
    }
    while (d[1]--) rt[1] = pop(rt[1]);
    while (rt[1]) {
        sum -= tr[rt[1]].v;
        rt[1] = pop(rt[1]);
    }
    cout << sum << endl;
    return 0;
}