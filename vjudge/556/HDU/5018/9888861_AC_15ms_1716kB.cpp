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
ll dp[maxn];
int main() {
    ios::sync_with_stdio(false);
    ll n, a, b, c;
    cin >> n;
    while (n--) {
        cin >> dp[0] >> dp[1] >> c;
        if (c == dp[0] || c == dp[1]) {
            cout << "Yes" << endl;
            continue;
        }
        REP(i, 2, 60) {
            dp[i] = dp[i - 1] + dp[i - 2];
            if (dp[i] == c) {
                cout << "Yes" << endl;
                goto fuck;
            } else if (dp[i] > c) {
                break;
            }
        }
        cout << "No" << endl;
    fuck:;
    }
    return 0;
}
