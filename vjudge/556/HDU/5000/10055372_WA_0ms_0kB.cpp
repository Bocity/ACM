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
ll dp[MAXN];
int main() {
    ios::sync_with_stdio(false);
    ll n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        ll fuck = 0;
        REP(i, 0, n) {
            cin >> ar[i];
            fuck += ar[i];
        }
        fuck /= 2;
        mems(dp, 0);
        dp[0] = 1;
        REP(i, 0, n) {
            PER(k, 1, fuck) {
                int sz = min(ar[i], k) + 1;
                PER(j, 1, sz) {
                    dp[k] = (dp[k] + dp[k - j]) % MOD;
                }
            }
        }
        cout << dp[fuck] << endl;
    }
    return 0;
}