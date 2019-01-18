#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n) -1; i >= x; --i)
#define endl "\n"
#define DE puts("----------")
#define CASE(i, ans) cout << "Case #" << (i) << ": " << (ans) << "\n"
#define lowbit(x) ((x) & (-(x)))
#define sqr(x) ((x) * (x))
#define eps 1e-9
#define PI acos(-1.0)
#define pii pair<int, int>
#define MOD 1000000007
#define y second
#define x first
using namespace std;
typedef long long ll;
const int maxn = 10005;
ll n, m, k;
const ll INF = 1e15;
vector<pii> q;
int vis[300][300];
bool check2(pii p1, pii p2, pii p3) {
    if (p3.x <= p2.x && p3.x >= p1.x && p3.y <= p1.y && p3.y >= p2.y) return false;
    return true;
}
bool check4(pii p1, pii p2, pii p3) {
    if (p3.x < p2.x && p3.x > p1.x && p3.y < p1.y && p3.y > p2.y) return true;
    return false;
}
bool check(pii p1, pii p2, pii p3, pii p4) {
    bool ans = true;
    ans &= check2(p1, p2, p3);
    ans &= check2(p1, p2, p4);
    ans &= check2(p1, p2, pii(p3.x, p4.y));
    ans &= check2(p1, p2, pii(p4.x, p3.y));
    ans &= check2(p3, p4, p1);
    ans &= check2(p3, p4, p2);
    ans &= check2(p3, p4, pii(p1.x, p2.y));
    ans &= check2(p3, p4, pii(p2.x, p1.y));
    return ans;
}
bool check3(pii p1, pii p2, pii p3, pii p4) {
    bool ans = true;
    bool ans2 = true;
    ans &= check4(p1, p2, p3);
    ans &= check4(p1, p2, p4);
    ans &= check4(p1, p2, pii(p3.x, p4.y));
    ans &= check4(p1, p2, pii(p4.x, p3.y));
    ans2 &= check4(p3, p4, p1);
    ans2 &= check4(p3, p4, p2);
    ans2 &= check4(p3, p4, pii(p1.x, p2.y));
    ans2 &= check4(p3, p4, pii(p2.x, p1.y));
    return (ans | ans2);
}
int main() {
    while (cin >> n && n) {
        memset(vis, 0, sizeof vis);
        q.clear();
        REP(i, 0, n) {
            int xx, yy;
            cin >> xx >> yy;
            vis[xx][yy] = 1;
            q.push_back(pii(xx, yy));
        }
        ll ans = -1;
        REP(i, 0, n) {
            REP(j, 0, n) {
                if (q[i].x > q[j].x || q[i].y < q[j].y) continue;
                if (q[i].x == q[j].x || q[i].y == q[j].y) continue;
                REP(ii, 0, n) {
                    if (ii == i || ii == j) continue;
                    REP(jj, 0, n) {
                        if (q[ii].x > q[jj].x || q[ii].y < q[jj].y) continue;
                        if (q[ii].x == q[jj].x || q[ii].y == q[jj].y) continue;
                        if (jj == i || jj == j) continue;
                        pii p1 = q[i], p2 = q[j], p3 = q[ii], p4 = q[jj];
                        // cout << "(" << p1.x << "," << p1.y << ")"
                        //      << "(" << p2.x << "," << p2.y << ")"
                        //      << "(" << p3.x << "," << p3.y << ")"
                        //      << "(" << p4.x << "," << p4.y << ")" << endl;
                        if (vis[p1.x][p2.y] && vis[p2.x][p1.y] && vis[p3.x][p4.y] && vis[p4.x][p3.y]) {
                            // cout << 1ll * abs((p1.x - p2.x) * (p2.y - p1.y)) + abs((p3.x - p4.x) * (p4.y - p3.y)) << endl;
                            if (check(p1, p2, p3, p4)) {
                                ans = max(ans, 1ll * abs((p1.x - p2.x) * (p2.y - p1.y)) + abs((p3.x - p4.x) * (p4.y - p3.y)));
                            } 
                            else if (check3(p1, p2, p3, p4)) {
                                ans = max(ans, 1ll*max(abs((p1.x - p2.x) * (p2.y - p1.y)), abs((p3.x - p4.x) * (p4.y - p3.y))));
                            }
                        }
                    }
                }
            }
        }
        if (ans == -1) {
            cout << "imp" << endl;
        } else
            cout << ans << endl;
    }
    return 0;
}
