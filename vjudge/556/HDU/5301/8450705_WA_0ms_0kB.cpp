#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
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
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
long long n, m, T, x, y, min1, ans, flag;
int main() {
    while (cin >> n >> m >> x >> y) {
        x = max(x - 1, n - x);
        y = max(y - 1, m - y);
        ans = min(x, y);
        x = max(x, (n + 1) / 2);
        y = max(y, (m + 1) / 2);
        ans = max(ans, min(x, y));
        cout << ans << endl;
    }
    return 0;
}