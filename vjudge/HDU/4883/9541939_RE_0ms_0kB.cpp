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
const int MAXN = 10000;
ll sum[MAXN << 4], add[MAXN << 4];
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
// int read() {
//     int f = 1, n = 0;
//     char ch;
//     ch = getchar();
//     while (ch < '0' || ch > '9') {
//         if (ch == '-') f = -1;
//         ch = getchar();
//     }
//     while (ch <= '9' && ch >= '0') {
//         n = n * 10 + ch - '0';
//         ch = getchar();
//     }
//     return f * n;
// }
int main() {
    // ios::sync_with_stdio(false);
    int T, n, ans;
    cin >> T;
    while (T--) {
        memset(sum, 0, sizeof sum);
        memset(add, 0, sizeof add);
        ans = 0;
        cin >> n;
        build(1, 3000, 1);
        int num, h, m, l, r;
        for (int i = 1; i <= n; i++) {
            cin >> num;
            scanf("%d:%d", &h, &m);
            l = h * 100 + m + 1;
            scanf("%d:%d", &h, &m);
            r = h * 100 + m + 1;
            update2(l, r - 1, num, 1, 3000, 1);
        }
        ans = sum[1];
        cout << ans << endl;
    }
    return 0;
}