#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
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
const int maxn = 10000;
pii ar[maxn];
map<pii, int> mp;
int main() {
    ios::sync_with_stdio(false);
    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        REP(i, 0, n) {
            cin >> ar[i].first >> ar[i].second;
        }
        ll ans = 0;
        ll dx, dy, g;
        REP(i, 0, n) {
            mp.clear();
            REP(j, i + 1, n) {
                dx = ar[i].first - ar[j].first;
                dy = ar[i].second - ar[j].second;
                g = __gcd(dx, dy);
                dx /= g;
                dy /= g;
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }
                if (dx && !dy) dx = 1;
                if (!dx && dy) dy = 1;
                mp[pii(dx, dy)]++;
            }
            ll temp;
            for (auto i : mp) {
                temp = i.second;
                ans += temp * (temp - 1) / 2;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
