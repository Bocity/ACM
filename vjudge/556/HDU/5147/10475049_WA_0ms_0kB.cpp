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
const int N = 60000;
int a[N];
int f[N];
int c[N], n;
int get(int x) {
    int s = 0;
    for (; x; x -= x & -x) s += c[x];
    return s;
}
void update(int x, int s) {
    for (; x <= n; x += x & -x) c[x] += s;
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ll ans = 0;
        REP(i, 0, n) {
            cin >> a[i];
        }
        mems(c, 0);
        REP(i, 0, n) {
            f[i] = n - a[i] - (i - get(a[i]));
            update(a[i], 1);
        }
        // REP(i, 0, n) {
        //     REP(j, i + 1, n) {
        //         ans += (f[i] - f[j] - 1) * f[j];
        //     }
        // }
        // cout << ans << endl;
        // ans = 0;
        ll pre = 0;
        PER(i, 0, n) {
            ans += pre * f[i] - (ll) i * f[i] * f[i] - (ll) i * f[i];
            pre += f[i];
        }
        // ans += f[0] * f[0] + f[0];
        cout << ans << endl;
    }
    return 0;
}