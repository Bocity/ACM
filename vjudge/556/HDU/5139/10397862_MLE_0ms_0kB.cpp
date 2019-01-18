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
ll dp[10000105];
int main() {
    ios::sync_with_stdio(false);
    int n;
    ll ans = 1;
    dp[1] = 1;
    ll temp = 2;
    REP(i, 2, 10000010) {
        dp[i] = (dp[i - 1] * temp) % MOD;
        temp = temp * (i + 1) % MOD;
    }
    while (cin >> n) {
        cout << dp[n] << endl;
    }
    return 0;
}