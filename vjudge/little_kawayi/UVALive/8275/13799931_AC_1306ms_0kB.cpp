#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int N = 505;
const int inf = 1000000;
const int M = N * N * N * 2;
int n, d, tot, ed, S, T, id[25][25], fir[N], gap[N], h[N], pos[N];
vector<int> ans;
struct E {
    int u, v, w, nxt;
} e[25 * 25 * 25 * 2];
void adde(int x, int y, int z) {
    e[++ed].v = y;
    e[ed].u = x;
    e[ed].w = z;
    e[ed].nxt = fir[x];
    fir[x] = ed;
    e[++ed].v = x;
    e[ed].u = y;
    e[ed].w = 0;
    e[ed].nxt = fir[y];
    fir[y] = ed;
}
int sap(int x, int flow) {
    if (x == T) return flow;
    int i, minh = tot, dec = 0, tmp;
    for (i = fir[x]; i; i = e[i].nxt)
        if (e[i].w) {
            if (h[x] == h[e[i].v] + 1) {
                tmp = sap(e[i].v, min(flow - dec, e[i].w));
                e[i].w -= tmp;
                e[i ^ 1].w += tmp;
                dec += tmp;
                if (h[S] >= tot) return dec;
                if (dec == flow) return flow;
            }
            if (h[e[i].v] < minh) minh = h[e[i].v];
        }
    if (!dec) {
        if (!(--gap[h[x]])) h[S] = tot;
        ++gap[h[x] = minh + 1];
    }
    return dec;
}
int maxflow() {
    int i, res = 0;
    for (i = 1; i <= tot; ++i) gap[i] = h[i] = 0;
    for (gap[0] = tot; h[S] < tot; res += sap(S, inf))
        ;
    return res;
}
main() {
    int i, j, k;
    for (; scanf("%d", &n), n;) {
        scanf("%d", &d);
        tot = d;
        S = ++tot;
        T = ++tot;
        for (ed = i = 1; i < N; ++i) fir[i] = 0;
        for (i = 1; i <= d; ++i) adde(i, T, 0);
        for (i = 1; i <= d; ++i) {
            for (j = i; j <= d; ++j) {
                id[i][j] = ++tot;
                adde(S, tot, 0);
                pos[tot] = ed - 1;
                for (k = i; k <= j; ++k) adde(tot, k, inf);
            }
        }
        ans.clear();
        for (i = 1; i <= n; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            int z = id[x][y];
            int p = pos[z];
            e[p].w++;
            int flag = 0;
            for (; !maxflow();) {
                for (j = 1; j <= d; ++j) e[j * 2].w++;
                flag = 1;
            }
            if (flag) ans.pb(i);
        }
        for (i = 0; i + 1 < ans.size(); ++i) printf("%d ", ans[i]);
        printf("%d\n", ans[i]);
    }
}