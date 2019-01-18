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
multiset<ll> st1, st2;
set<ll, greater<ll>> st;
vector<ll> ve;
int main() {
    ios::sync_with_stdio(false);
    ll t, x, y, k;
    cin >> t;
    while (t--) {
        cin >> x >> y >> k;
        st1.clear(), st2.clear(), st.clear();
        ve.clear();
        ll temp = x;
        REP(i, 2, temp) {
            while (temp % i == 0) {
                temp /= i;
                st1.insert(i);
            }
        }
        temp = y;
        REP(i, 2, temp) {
            while (temp % i == 0) {
                temp /= i;
                st2.insert(i);
            }
        }

        for (auto i : st1) {
            auto pos = st2.lower_bound(i);
            if (pos != st2.end()) {
                ve.push_back(i);
                st2.erase(pos);
            }
        }
        st.insert(1);
        REP(i, 0, ve.size()) {
            for (auto j : st) {
                st.insert(j * ve[i]);
            }
        }
        ll sz = st.size();
        if (sz < k) {
            cout << -1 << endl;
            continue;
        }
        ve.clear();
        for (auto i : st) {
            ve.push_back(i);
        }
        cout << ve[k - 1] << endl;
    }
    return 0;
}
