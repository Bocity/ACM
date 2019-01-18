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
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 560000;
set<ll, greater<ll>> st;
vector<ll> ve;
int main() {
    ios::sync_with_stdio(false);
    ll t, x, y, k;
    cin >> t;
    while (t--) {
        cin >> x >> y >> k;
        st.clear();
        ve.clear();
        ll g = __gcd(x, y);
        int temp = sqrt(__gcd(x, y) * 1.0) + 1;
        REP(i, 1, temp) {
            if (g % i == 0) {
                ve.push_back(i);
                ve.push_back(g / i);
            }
        }
        sort(ve.begin(), ve.end());
        auto pos = unique(ve.begin(), ve.end());
        ve.erase(pos, ve.end());
        ll sz = ve.size();
        if (sz < k) {
            cout << -1 << endl;
            continue;
        }
        cout << __gcd(x, y) / ve[k - 1] << endl;
    }
    return 0;
}
