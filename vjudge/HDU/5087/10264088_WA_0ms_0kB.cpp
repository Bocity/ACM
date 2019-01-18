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
long long a[maxn], n, dp[maxn], dp2[maxn], dp3[maxn], dp4[maxn];
map<long long, bool> vis;
void stay() {
    vis.clear();
    cin >> n;
    REP(i, 0, n) {
        cin >> a[i];
    }
    ll len = 0, pos, maxx;
    REP(i, 0, n) {
        pos = lower_bound(dp, dp + len, a[i]) - dp;
        if (pos == len) {
            dp[pos] = a[i];
        }
        len = max(len, pos + 1);
        dp2[i] = len;
    }
    ll ans = 0, len2 = 0;
    // REP(i, 0, len) cout << dp[i] << " ";
    REP(j, 0, len) {
        len2 = 0;
        mems(dp3, 0);
        mems(dp4, 0);
        REP(i, 0, n) {
            if (dp[j] == a[i] && !vis[a[i]]) {
                continue;
                vis[a[i]] = true;
            }
            pos = lower_bound(dp3, dp3 + len2, a[i]) - dp3;
            dp3[pos] = a[i];
            len2 = max(len2, pos + 1);
            dp4[i] = len2;
            ans = max(len2, ans);
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) stay();
    return 0;
}