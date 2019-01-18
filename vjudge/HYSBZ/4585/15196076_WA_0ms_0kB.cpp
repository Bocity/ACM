#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#define REP(i, x, n) for (int i = x; i < n; ++i)
#define PER(i, x, n) for (int i = (n - 1); i >= x; --i)
#define N 600010
#define ll long long
using namespace std;
using namespace __gnu_pbds;
#define param ll, less<ll>, binomial_heap_tag
__gnu_pbds::priority_queue<param> pq[N];

int n, m, tot, fa[N], w[N], d[N], rt[N];
int f[N]; //记录是否在同一集合，并查集实现
int fd(int x) {
    if (x == f[x]) return f[x];
    return f[x] = fd(f[x]);
}
ll sum;
// struct heap {
//     int l, r, dis;
//     ll v;
// } tr[N];
// inline int merge(int x, int y) {
//     if (!x || !y) return x + y;
//     if (tr[x].v < tr[y].v) swap(x, y);
//     tr[x].r = merge(tr[x].r, y);
//     if (tr[tr[x].l].dis < tr[tr[x].r].dis) swap(tr[x].l, tr[x].r);
//     if (!tr[x].r)
//         tr[x].dis = 0;
//     else
//         tr[x].dis = tr[tr[x].r].dis + 1;
//     return x;
// }
// inline int pop(int x) {
//     return merge(tr[x].l, tr[x].r);
// }
int main() {
    ios::sync_with_stdio(0);
    sum = 0;
    memset(d, 0, sizeof d);
    cin >> n >> m;
    f[1] = 1;
    REP(i, 2, n + m + 1) {
        cin >> fa[i] >> w[i];
        sum += w[i];
        d[fa[i]]++;
        f[i] = i;
    }
    PER(i, 2, n + m + 1) {
        ll r = 0, l = 0;
        if (i <= n) {
            int fx = fd(i);
            while (--d[i]) pq[fx].pop();
            r = pq[fx].top();
            pq[fx].pop();
            l = pq[fx].top();
            pq[fx].pop();
        }
        int L = l + w[i];
        int R = r + w[i];
        __gnu_pbds::priority_queue<param> tmp;
        tmp.push(L);
        tmp.push(R);
        int fxx = fd(i);
        pq[fxx].join(tmp);
        int fx = fd(fa[i]);
        int fy = fd(i);
        if (fx == fy) continue;
        pq[fx].join(pq[fy]);
        f[fy] = fx;
    }
    while (d[1]--) pq[1].pop();
    while (!pq[1].empty()) {
        sum -= pq[1].top();
        pq[1].pop();
    }
    cout << sum << endl;
    return 0;
}