#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAXN = 10005;
int sum[MAXN << 2], add[MAXN << 2];
void pushup(int rt) {
    sum[rt] = max(sum[rt << 1], sum[rt << 1 | 1]);
}
void pushdown(int rt, int m /*区间长度*/) {
    if (add[rt] != 0) {
        add[rt << 1] += add[rt];
        add[rt << 1 | 1] += add[rt];
        sum[rt << 1] += add[rt];
        sum[rt << 1 | 1] += add[rt];
        add[rt] = 0;
        //  sum[rt] = max(sum[rt << 1] + add[rt << 1], sum[rt << 1 | 1] + add[rt << 1 | 1]);
    }
    return;
}
void build(int l, int r, int rt /*=1*/) {
    add[rt] = 0;
    if (l == r) {
        sum[rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
    return;
}
void update(int L /*需要更新的点*/, int c, int l, int r, int rt /*=1*/) { //单点
    if (L == l && l == r) {
        sum[rt] += c;
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, c, lson);
    else
        update(L, c, rson);
    pushup(rt);
    return;
}

int query(int L, int R, int l, int r, int rt /*=1*/) {
    if (L <= l && r <= R) {
        return sum[rt];
    }
    int ret = 0;
    int m = (l + r) >> 1;
    if (L < m) ret += query(L, R, lson);
    if (m < R) ret += query(L, R, rson);
    return ret;
}
void update2(int L /*左*/, int R /*右端点*/, int c, int l, int r, int rt /*=1*/) {
    if (L <= l && r <= R) {
        add[rt] += c;
        sum[rt] += c;
        return;
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update2(L, R, c, lson);
    if (m < R) update2(L, R, c, rson);
    pushup(rt);
    return;
}
int query2(int L, int R, int l, int r, int rt /*=1*/) {
    if (l == r) {
        return sum[rt];
    }
    pushdown(rt, r - l + 1);
    int m = (l + r) >> 1;
    int ret1 = 0, ret2 = 0;
    if (L <= m) ret1 = query2(L, R, lson);
    if (m < R) ret2 = query2(L, R, rson);
    return max(ret1, ret2);
}
int discrete(int data[] /*初始数组*/, int n, int dis[] /*离散化数组*/, int idx[]) {
    int sub[n + 1];
    memcpy(sub, data, sizeof(sub));
    sort(sub + 1, sub + n + 1);
    int m = unique(sub + 1, sub + n + 1) - sub - 1;
    for (int i = 1; i <= n; i++) {
        dis[i] = lower_bound(sub + 1, sub + 1 + m, data[i]) - sub;
        idx[dis[i]] = data[i];
    }
    return m;
}
int read() {
    int f = 1, n = 0;
    char ch;
    ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0') {
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return f * n;
}
int main() {
    ios::sync_with_stdio(false);
    int T, n, ans;
    T = read();
    while (T--) {
        memset(sum, 0, sizeof sum);
        memset(add, 0, sizeof add);
        ans = 0;
        n = read();
        build(0, 2400, 1);
        int num, h, m, l, r;
        for (int i = 1; i <= n; i++) {
            num = read();
            scanf("%d:%d", &h, &m);
            l = h * 100 + m;
            scanf("%d:%d", &h, &m);
            r = h * 100 + m;
            update2(l, r - 1, num, 0, 2500, 1);
        }
        ans = 0;
        ans = max(ans, query2(0, 2500, 0, 2500, 1));
        cout << ans << endl;
    }
    return 0;
}