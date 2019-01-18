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

#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 258280327;
const int INF = 0x3f3f3f3f;
ll dp[2][10];
int main() {
    ios::sync_with_stdio(false);
    int t, index, a, b, n, temp, sum;
    cin >> t;
    while (t--) {
        mems(dp, 0);
        index = sum = 0;
        cin >> n >> a >> b;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            sum = (sum + temp) % 9;
            for (int j = 0; j < 9; j++) {
                dp[index][j] = 0;
            }
            dp[index][temp % 9]++;
            for (int j = 0; j < 9; j++) {
                dp[index][j] = (dp[index][j] + dp[!index][j]) % MOD;
                dp[index][(j + temp) % 9] = (dp[index][(j + temp) % 9] + dp[!index][j]) % MOD;
            }
            index = !index;
        }
        // for (int i = 0; i < 9; i++) {
        //     cout << dp[!index][i] << " ";
        // }
        // cout << endl;
        if (sum != a % 9 && sum != b % 9 && sum != (a + b) % 9) {
            cout << 0 << endl;
            continue;
        }
        if (a == b)
            cout << (dp[!index][a % 9] + 1) % MOD << endl;
        else
            cout << dp[!index][a % 9] << endl;
    }
    return 0;
}