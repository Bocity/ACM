#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const long long MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;
int t;
long long a[maxn], n, dp[maxn], dp2[maxn];

void stay() {
    cin >> n;
    REP(i, 0, n) {
        cin >> a[i];
    }
    ll len = 0, pos;
    REP(i, 0, n) {
        pos = lower_bound(dp, dp + len, a[i]) - dp;
        dp[pos] = a[i];
        len = max(len, pos + 1);
        dp2[i] = len;
    }
    ll ans = 0;
    REP(i, 0, n) {
        ans = max(dp2[i], ans);
    }
    if (is_sorted(a, a + n) && n > 1 && a[0] < a[1]) {
        cout << n - 1 << endl;
    } else {
        cout << ans << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) stay();
    return 0;
}