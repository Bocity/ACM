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
using namespace std;
ll n;
int main() {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        memset(vis, 0, sizeof vis);
        REP(i, 0, n) {
            cin >> p[i].x >> p[i].y;
            vis[p[i].x + 100][p[i].y + 100] = true;
        }
        int ans = 0;
        REP(i, 0, n) {
            REP(j, i + 1, n) {
                Point tmp;
                tmp.x = (p[i].x + p[j].x + p[j].y - p[i].y);
                tmp.y = (p[i].y + p[j].y + p[i].x - p[j].x);
                if (tmp.x % 2 != 0 || tmp.y % 2 != 0) continue;
                tmp.x /= 2, tmp.y /= 2;
                if (tmp.x < -100 || tmp.x > 100 || tmp.y < -100 || tmp.y > 100 || !vis[tmp.x + 100][tmp.y + 100])
                    continue;
                tmp.x = (p[i].x + p[j].x + p[i].y - p[j].y);
                tmp.y = (p[i].y + p[j].y + p[j].x - p[i].x);
                if (tmp.x % 2 != 0 || tmp.y % 2 != 0) continue;
                tmp.x /= 2, tmp.y /= 2;
                if (tmp.x < -100 || tmp.x > 100 || tmp.y < -100 || tmp.y > 100 || !vis[tmp.x + 100][tmp.y + 100])
                    continue;
                ans++;
            }
        }
        cout << ans / 2 << endl;
    }
    return 0;
}