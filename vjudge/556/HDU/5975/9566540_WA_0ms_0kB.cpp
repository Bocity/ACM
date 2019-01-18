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
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
ll lowbit(ll x) {
    return x & (-x);
}
ll query(ll x, ll n) {
    ll ans = 0;
    while (x <= n) {
        ans++;
        x += lowbit(x);
    }
    return ans;
} // 查询2
ll cal(ll x) {
    ll ans = 0;
    ll tmp = 1;
    for (ll i = 0; tmp <= x; i++) {
        ans += ((x / tmp) - (x / (tmp << 1))) * tmp;
        tmp <<= 1;
    }
    return ans;
}
ll n, q;
int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> q) {
        while (q--) {
            int xx;
            cin >> xx;
            if (xx == 1) {
                int aa, bb;
                cin >> aa >> bb;
                cout << cal(bb) - cal(aa - 1) << endl;
            } else {
                int aa;
                cin >> aa;
                cout << query(aa, n) << endl;
            }
        }
    }
    return 0;
}