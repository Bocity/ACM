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
#include <unordered_map>
#include <vector>

#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
#define eps 1e7
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
int a[2001][2001];
inline ll readT() {
    char c;
    ll ret = 0, flag = 0;
    while (c = getchar(), (c < '0' || c > '9') && c != '-')
        ;
    if (c == '-')
        flag = 1;
    else
        ret = c ^ 48;
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c ^ 48);
    return flag ? -ret : ret;
}
ll PowerMod(ll a, ll b, ll c) {
    ll ans = 1;
    a = a % c;
    while (b > 0) {
        if (b % 2 == 1) ans = (ans * a) % c;
        b = b / 2;
        a = (a * a) % c;
    }
    return ans;
}
int main() {
    cin >> T;
    unordered_map<double, ll> mp;
    unordered_map<double, bool> vis;
    while (T--) {
        n = readT();
        ans = 0;
        for (int i = 1; i <= n; i++) {
            x = readT();
            y = readT();
            p[i].x = x;
            p[i].y = y;
        }
        sort(p + 1, p + 1 + n, cmp);
        mp.clear();
        double pre, temp;
        for (int i = 1; i <= n; i++) {
            vis.clear();
            for (int j = i + 1; j <= n; j++) {
                if (p[i].y != p[j].y)
                    temp = (double) ((ll)(((double) (p[i].x - p[j].x) / (p[i].y - p[j].y)) * 1e7)) / 1e7;
                else
                    temp = 1e15;
                if (vis.find(temp) != vis.end()) continue;
                vis[temp] = 1;
                if (p[i].y - p[j].y != 0) {
                    if (mp.find(temp) == mp.end())
                        mp[temp] = 2;
                    else
                        mp[temp]++;
                } else {
                    if (mp.find(1e15) == mp.end())
                        mp[1e15] = 2;
                    else
                        mp[1e15]++;
                }
            }
        }
        for (auto i : mp) {
            ans = (ans + PowerMod(2, i.second, (ll)(1e9 + 7)) - i.second - 1ll) % (ll)(1e9 + 7);
        }
        cout << ans << "\n";
    }
    return 0;
}