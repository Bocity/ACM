#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#define REP(i, x, n) for (long long i = (x); i < (n); ++i)
#define PER(i, x, n) for (long long i = (n) -1; i >= x; --i)
#define endl "\n"
#define DE(x) cout << "--------\n" << (x) << "----------\n"
#define CASE(i, ans) cout << "Case #" << (i) << ": " << (ans) << "\n"
// #define lowbit(x) ((x) & (-(x)))
#define sqr(x) ((x) * (x))
#define eps 1e-9
#define PI acos(-1.0)
#define testin freopen("test.in", "r", stdin)
#define testout freopen("test.out", "w", stdout)
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef bitset<1005> Bitset;
const int maxn = 1000150;
const int N = 1000150;
template <class T> void read(T &num) {
    char CH;
    bool F = false;
    num = 0;
    for (CH = getchar(); CH < '0' || CH > '9'; F = CH == '-', CH = getchar())
        ;
    for (num = 0; CH >= '0' && CH <= '9'; num = num * 10 + CH - '0', CH = getchar())
        ;
    F && (num = -num);
}
char stk[600];
int tp = 0;
template <class T> inline void print(T p) {
    if (!p) {
        puts("0");
        return;
    }
    while (p) stk[++tp] = p % 10, p /= 10;
    while (tp) putchar(stk[tp--] + '0');
    putchar('\n');
}
ll n, m, ans;
ll a[100005], b[100005], dp[100005], dp2[100005], dp1[100005];
void stay() {
    cin >> n >> m;
    REP(i, 0, n) {
        cin >> a[i] >> b[i];
    }
    ans = 0;
    ll len = 0, pos, minn, minn2;
    for (int i = 0; i < n; i++) {
        pos = lower_bound(dp, dp + len, a[i]) - dp;
        dp[pos] = a[i];
        len = max(len, pos + 1);
        dp2[i] = len;
    }
    ll len2, pos2;
    for (int i = 0; i < n; i++) {
        pos = lower_bound(dp, dp + len2, a[i]) - dp;
        pos2 = lower_bound(dp, dp + len2, b[i]) - dp;
        if (pos == pos2) {
            dp[pos] = min(a[i], b[i]);
            len2 = max(len2, pos + 1);
            dp2[i] = len2;
        } else {
            pos = max(pos, pos2);
            pos2 = (pos == pos2) ? b[i] : a[i];
            dp[pos] = pos2;
            len2 = max(len2, pos + 1);
            dp2[i] = len2;
        }
    }
    // cout << len2 << endl;
    // REP(i, 0, 5) cout << dp[i] << " ";
    cout << len + min(len2 - len, m) << endl;
    return;
}
int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        stay();
    }
    return 0;
}