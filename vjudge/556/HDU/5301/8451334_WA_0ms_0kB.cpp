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
int main() {
    ios::sync_with_stdio(false);
    ll n, m, x, y, ans, x1, y1;
    while (cin >> n >> m >> x >> y) {
        ll rawx = x, rawy = y;
        x = max(x - 1, n - x);
        y = max(y - 1, m - y);
        ans = min(x, y);
        x1 = (n + 1) / 2;
        y1 = (m + 1) / 2;
        if (x1 == rawx && y1 == rawy) {
            if (x1 == y1) ans = max(ans, x1 - 1);
            else ans = max(ans, min(x, y));
        }
        else 
            ans = max(ans, min(x, y));
        cout << ans << endl;
    }
    return 0;
}