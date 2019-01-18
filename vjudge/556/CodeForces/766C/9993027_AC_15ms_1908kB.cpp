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
const int maxn = 1010;
ll dp[maxn], dpl[maxn];
int al[26];
int main() {
    ios::sync_with_stdio(false);
    int n;
    string str;
    cin >> n >> str;
    REP(i, 0, 26) cin >> al[i];
    mems(dpl, INF);
    mems(dp, 0);
    dp[0] = 1, dpl[0] = 0;
    int len, maxlen = 0;
    REP(i, 0, str.size()) {
        len = INF;
        PER(j, 0, i + 1) {
            len = min(len, al[str[j] - 'a']);
            if (i - j + 1 > len) break;
            maxlen = max(maxlen, i - j + 1);
            dp[i + 1] = (dp[i + 1] + dp[j]) % MOD;
            dpl[i + 1] = min(dpl[i + 1], dpl[j] + 1);
        }
    }
    // REP(i, 0, n + 1) cout << dp[i] << " ";
    cout << dp[n] << endl;
    cout << maxlen << endl;
    cout << dpl[n] << endl;
    return 0;
}