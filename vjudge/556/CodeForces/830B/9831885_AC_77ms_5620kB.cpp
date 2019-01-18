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
const int N = 110000;
int c[N], n;
set<pii> st;
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
    int temp;
    while (cin >> n) {
        st.clear();
        REP(i, 1, n + 1) {
            cin >> temp;
            st.insert(pii(temp, i));
        }
        mems(c, 0);
        REP(i, 1, n + 1) update(i, 1);
        pii pre = pii(0, 0);
        ll ans = 0;
        REP(i, 1, n + 1) {
            pre.first = st.begin()->first;
            auto pos = st.lower_bound(pre);
            if (pos->first == st.begin()->first) {
                ans += get(pos->second) - get(pre.second);
            } else {
                pos = st.begin();
                ans += get(n) - get(pre.second) + get(pos->second);
            }
            update(pos->second, -1);
            pre = *pos, st.erase(pos);
        }
        cout << ans << endl;
    }
    return 0;
}