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
const int maxn = 6 * 1e5;
int pre[maxn], nxt[maxn], pos[maxn], a[maxn];
int n, k;
void shit(int x) {
    pre[nxt[x]] = pre[x];
    nxt[pre[x]] = nxt[x];
}
ll fuck(int x) {
    ll ret = 0;
    vector<int> vn, vp;
    for (int i = x, cnt = 0; i && cnt <= k; i = pre[i], cnt++) {
        vp.push_back(i);
    }
    for (int i = x, cnt = 0; i && cnt <= k; i = nxt[i], cnt++) {
        vn.push_back(i);
    }
    vp.push_back(0);
    vn.push_back(n + 1);
    REP(i, 0, k) {
        if (i + 1 < vp.size() && k - i < vn.size()) {
            ret += (vp[i] - vp[i + 1]) * (vn[k - i] - vn[k - i - 1]);
            // cout << vp[i] - vp[i + 1] << " " << vn[k - i] - vn[k - i - 1] << " " << ret << endl;
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        REP(i, 1, n + 1) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        REP(i, 0, n + 2) {
            pre[i] = i - 1;
            nxt[i] = i + 1;
        }
        nxt[n] = pre[1] = 0;
        ll ans = 0;
        REP(i, 1, n + 1) {
            ans += i * fuck(pos[i]);
            shit(pos[i]);
        }
        cout << ans << endl;
    }
}