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
int digit[1100];
int n;
int dp[1100][1100];
int mem[1100][1100];
ll fuck;
int qpow[1100];
pii dfs(int pos, int pre, bool limit) {
    if (pre > n) return {0, 0};
    if (pos == -1) {
        if (pre == n) return {1, 0};
        return {0, 0};
    }
    if (!limit && ~dp[pos][pre]) {
        // fuck = (fuck + mem[pos][pre]) % MOD;
        return {dp[pos][pre], mem[pos][pre]};
    }
    ll ans = 0, add = 0;
    int to = limit ? digit[pos] : 1;
    REP(d, 0, to + 1) {
        pii temp = dfs(pos - 1, pre + d, limit && d == to);
        ans = (ans + temp.first) % MOD;
        add = (add + temp.second + d * temp.first * qpow[pos]) % MOD;
    }
    // fuck = (add + fuck) % MOD;
    if (!limit) {
        dp[pos][pre] = ans;
        mem[pos][pre] = add;
    }
    return {ans, add};
}
string num;
ll solve() {
    int sz = num.size();
    for (int i = 0, j = sz - 1; i < sz; i++, j--) {
        digit[j] = num[i] - '0';
    }
    REP(i, 0, sz) {
        if (digit[i]) {
            digit[i] = 0;
            if (i == sz - 1) sz--;
            break;
        } else {
            digit[i] = 1;
        }
    }
    cout << dfs(sz - 1, 0, true).second << endl;
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    qpow[0] = 1;
    REP(i, 1, 1010) {
        qpow[i] = 2ll * qpow[i - 1] % MOD;
    }
    while (cin >> n) {
        cin >> num;
        mems(dp, -1);
        mems(mem, 0);
        fuck = 0;
        solve();
        // cout << fuck << endl;
    }
    return 0;
}