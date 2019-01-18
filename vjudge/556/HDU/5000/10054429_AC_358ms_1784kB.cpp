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
#include <sstream>
#include <string>
#include <vector>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAXN = 3000;
int ar[MAXN];
ll dp[2][MAXN];
int main() {
    ios::sync_with_stdio(false);
    ll n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        ll fuck = 0;
        REP(i, 1, n + 1) {
            cin >> ar[i];
            fuck += ar[i];
        }
        mems(dp, 0);
        dp[0][0] = dp[1][0] = 1;
        REP(i, 1, n + 1) {
            bool temp = i & 1;
            mems(dp[temp], 0);
            PER(k, 0, fuck) {
                REP(j, 0, ar[i] + 1) {
                    if (j > k) break;
                    dp[temp][k] = (dp[temp][k] + dp[!temp][k - j]) % MOD;
                }
            }
        }
        bool temp = n & 1;
        cout << dp[temp][fuck / 2] << endl;
    }
    return 0;
}