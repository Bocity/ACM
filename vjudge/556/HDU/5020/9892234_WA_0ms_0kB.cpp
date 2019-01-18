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
ll x1, x2, y1, y2, z1, z2;
inline bool check() {
    return x1 * y2 - x2 * y1 + y1 * z2 - y2 * z1 + z1 * x2 - z2 * x1 == 0;
}
int main() {
    ios::sync_with_stdio(false);
    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        REP(i, 0, n) {
            cin >> ar[i].first >> ar[i].second;
        }
        sort(ar, ar + n);
        ll ans = 0;
        REP(i, 0, n) {
            x1 = ar[i].first, x2 = ar[i].second;
            REP(j, i + 1, n) {
                z1 = ar[j].first, z2 = ar[j].second;
                REP(k, j + 1, n) {
                    y1 = ar[k].first, y2 = ar[k].second;
                    if (check())
                        ans++;
                    else
                        break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
