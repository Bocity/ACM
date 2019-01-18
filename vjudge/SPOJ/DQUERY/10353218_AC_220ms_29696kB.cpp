#include <bits/stdc++.h>
// 注意每次flag l r 的初始化 以及有可能会爆longlong
// 莫队算法时间复杂度 O（N^1.5）
using namespace std;
const long long maxn = 300000 + 10;
typedef long long ll;
struct node {
    int l, r, id;
} Q[maxn];
int n, m, k;
int L = 1, R = 0;
long long Ans = 0;
int pos[maxn];
long long ans[maxn];
int flag[maxn];
int a[maxn];
int vis[1000005] = {0};
bool cmp(node a, node b) {
    if (pos[a.l] == pos[b.l]) return a.r < b.r;
    return pos[a.l] < pos[b.l];
}
inline void add(int x) {
    if (!vis[a[x]]) {
        Ans++;
    }
    vis[a[x]]++;
}
inline void del(int x) {
    if (vis[a[x]] == 1) {
        Ans--;
    }
    vis[a[x]]--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Ans = 0;
    cin >> n;
    int sz = sqrt(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pos[i] = i / sz;
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].id = i;
    }
    sort(Q + 1, Q + 1 + m, cmp);
    L = 1, R = 0;
    memset(flag, 0, sizeof flag);
    for (int i = 1; i <= m; ++i) {
        while (R > Q[i].r) {
            del(R);
            R--;
        }
        while (R < Q[i].r) {
            R++;
            add(R);
        }
        while (L < Q[i].l) {
            del(L);
            L++;
        }
        while (L > Q[i].l) {
            L--;
            add(L);
        }
        ans[Q[i].id] = Ans;
    }

    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}