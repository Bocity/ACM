#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); i++)
#define PER(i, x, n) for (int i = (n); i >= (x); i--)
typedef long long ll;
#define endl "\n"
#define sqr(x) ((x) * (x))
struct Point {
    int x, y;

} p[1000];
bool vis[600][600];
bool pan(Point x, Point y, Point z) {
    int x1 = y.x - x.x, x2 = z.x - x.x;
    int y1 = y.y - x.y, y2 = z.y - x.y;
    if (x1 * y1 + x2 * y2 == 0) return true;
    return false;
}
ll dis(Point x, Point y) {
    return (sqr(x.x - y.x) + sqr(x.y - y.y));
}
using namespace std;
ll n;
int main() {
    ios::sync_with_stdio(0);
    while (cin >> n) {
        ll ans = 0;
        memset(vis, 0, sizeof vis);
        memset(p, 0, sizeof p);
        REP(i, 0, n) {
            cin >> p[i].x >> p[i].y;
            p[i].x += 100;
            p[i].y += 100;
            vis[p[i].x][p[i].y] = true;
        }
        REP(i, 0, n) {
            REP(j, i + 1, n) {
                REP(k, j + 1, n) {
                    // if (i != j && i != k && j != k)
                    if (pan(p[i], p[j], p[k]) && dis(p[i], p[j]) == dis(p[i], p[j])) {
                        if (vis[p[k].x + p[j].x - p[i].x][p[k].y + p[j].y - p[i].y]) {
                            // cout << p[i].x << "," << p[i].y << " " << p[j].x << "," << p[j].y << " " << p[k].x <<
                            // "," << p[k].y << endl;
                            ans++;
                        }
                    }
                }
            }
        }
        cout << ans + 2 / 3 << endl;
    }
    return 0;
}