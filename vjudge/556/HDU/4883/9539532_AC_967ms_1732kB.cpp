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
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
// #define lson l, m, rt << 1
// #define rson m + 1, r, rt << 1 | 1
// const int MAXN = 10005;
// int sum[MAXN << 2], add[MAXN << 2];
// void pushup(int rt) {
//     sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
// }
// void pushdown(int rt, int m /*区间长度*/) {
//     if (add[rt] != 0) {
//         add[rt << 1] += add[rt];
//         add[rt << 1 | 1] += add[rt];
//         sum[rt << 1] += add[rt] * (m - (m >> 1));
//         sum[rt << 1 | 1] += add[rt] * (m >> 1);
//         add[rt] = 0;
//     }
//     return;
// }
// void build(int l, int r, int rt /*=1*/) {
//     add[rt] = 0;
//     if (l == r) {
//         sum[rt] = 0;
//         return;
//     }
//     int m = (l + r) >> 1;
//     build(lson);
//     build(rson);
//     pushup(rt);
//     return;
// }
// void update2(int L /*左*/, int R /*右端点*/, int c, int l, int r, int rt /*=1*/) {
//     if (L <= l && r <= R) {
//         add[rt] += c;
//         sum[rt] += c * (r - l + 1);
//         return;
//     }
//     pushdown(rt, r - l + 1);
//     int m = (l + r) >> 1;
//     if (L <= m) update2(L, R, c, lson);
//     if (m < R) update2(L, R, c, rson);
//     pushup(rt);
//     return;
// }
// int query2(int L, int R, int l, int r, int rt /*=1*/) {
//     if (L <= l && r <= R) {
//         return sum[rt];
//     }
//     pushdown(rt, r - l + 1);
//     int m = (l + r) >> 1;
//     int ret = 0;
//     if (L <= m) ret += query2(L, R, lson);
//     if (m < R) ret += query2(L, R, rson);
//     return ret;
// }
int arr[2000];
int main() {
    ios::sync_with_stdio(false);
    int t, num, temp, n;
    int left, right;
    char ch;
    cin >> t;
    while (t--) {
        mems(arr, 0);
        cin >> n;
        int maxn = 0;
        int minn = 24 * 60;
        REP(i, n) {
            left = right = 0;
            cin >> num;
            cin >> temp;
            left += temp * 60;
            cin >> ch;
            cin >> temp;
            left += temp;
            cin >> temp;
            right += temp * 60;
            cin >> ch;
            cin >> temp;
            right += temp;
            maxn = max(maxn, right);
            minn = min(minn, left);
            for (int i = left; i < right; i++) arr[i] += num;
        }
        int ans = 0;
        for (int i = minn; i <= maxn; i++) ans = max(ans, arr[i]);
        cout << ans << endl;
    }
    return 0;
}