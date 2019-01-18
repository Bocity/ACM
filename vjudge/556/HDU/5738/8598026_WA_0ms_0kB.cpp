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
struct point {
    long long x, y;
} p[10005];
bool cmp(point x, point y) {
    if (x.x == y.x)
        return x.y < y.y;
    else
        return x.x < y.x;
}
bool in(point x, point y, point z) {
    point m, n;
    m.x = x.x - y.x;
    m.y = x.y - y.y;
    n.x = z.x - y.x;
    n.y = z.y - y.y;
    return (m.x * n.y == m.y * n.x);
}
long long x, y, T, n, k, sum, ans;
int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> x >> y;
            p[i].x = x;
            p[i].y = y;
        }
        sort(p + 1, p + 1 + n, cmp);
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++) {
                sum = 0;
                for (int k = 1; k <= n && k != i && k != j; k++) {
                    if (p[k].x > p[j].x || p[k].y > p[j].y) break;
                    if (p[k].x < p[i].x || (p[k].y < p[i].y)) continue;
                    if (in(p[k], p[i], p[j])) sum++;
                }
                ans = ((1 << sum) + ans) % (ll)(1e9 + 7);

                // cout << sum << "," << ans << "\n";
            }
        cout << ans << "\n";
    }
    return 0;
}