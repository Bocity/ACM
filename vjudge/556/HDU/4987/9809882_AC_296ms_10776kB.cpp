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
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 560000;
double dp[maxn];
double sum[maxn];
int main() {
    ios::sync_with_stdio(false);
    int n, m;
    dp[0] = sum[0] = 1;
    while (cin >> m >> n) {
        if (m >= n) {
            cout << fixed << setprecision(5) << pow(1 + 1.0 / m, n - 1) / m << endl;
        } else {
            n = min(maxn - 100, n);
            double f = 1.0 / m;
            REP(i, 1, min(m + 1, n + 1)) {
                dp[i] = sum[i - 1] * f;
                sum[i] = sum[i - 1] + dp[i];
            }
            REP(i, m + 1, n + 1) {
                dp[i] = (sum[i - 1] - sum[i - 1 - m]) * f;
                sum[i] = sum[i - 1] + dp[i];
            }
            cout << fixed << setprecision(5) << dp[n] << endl;
        }
    }
    return 0;
}