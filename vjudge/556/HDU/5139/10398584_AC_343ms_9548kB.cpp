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
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int dp[1000010];
int dp2[1000010];
int main() {
    ios::sync_with_stdio(false);
    dp[0] = 1;
    dp2[0] = 1;
    int n, cnt = 1;
    ll ans = 1;
    ll temp = 1;
    REP(i, 1, 10000010) {
        ans = ans * temp % MOD;
        temp = temp * (i + 1) % MOD;
        if (i % 10 == 0) {
            dp2[cnt] = temp;
            dp[cnt++] = ans;
        }
    }
    while (cin >> n) {
        int rem = n % 10;
        ll nn = n / 10;
        ans = dp[nn], temp = dp2[nn];
        nn = n - rem + 2;
        REP(i, 0, rem) {
            ans = ans * temp % MOD;
            temp = temp * (nn++) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}