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
#define all(a) (a).begin(), (a).end()
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int k;
ll dp[19][10][2];
int digit[19];
ll dfs(int pos, int preDigit, bool isLast, bool fuck) {
    // cout << pos << " " << preDigit << endl;
    if (pos == -1) {
        if (fuck) return 1;
        return 0;
    }
    if (!isLast && ~dp[pos][preDigit][fuck]) return dp[pos][preDigit][fuck];
    ll ans = 0;
    int to = isLast ? digit[pos] : 9;
    for (int d = 0; d <= to; d++)
        if ((pos % k == 0) || preDigit != d || (preDigit == 0 && !fuck))
            ans += dfs(pos - 1, d, isLast && d == to, d || fuck);
    return isLast ? ans : dp[pos][preDigit][fuck] = ans;
}
ll solve(ll x) {
    if (x == 0) return 1;
    int cnt = 0;
    while (x) {
        digit[cnt++] = x % 10;
        x /= 10;
    }
    return dfs(cnt - 1, -1, true, false) + 1;
}
int main() {
    ll l, r;
    memset(dp, -1, sizeof(dp));
    while (~scanf("%lld%lld%lld", &l, &r, &k)) {
        cout << solve(r) - solve(l - 1) << endl;
    }
}