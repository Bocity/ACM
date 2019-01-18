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
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 100010;
vector<int> v[N];
long long vvv[N] = {0};
int main() {
    long long T, n, m, a, b, q, u, vv, cmd, ans;
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        for (int i = 0; i < 100010; i++) v[i].clear();
        mems(vvv, 0);
        ans = 0;
        cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> cmd;
            if (cmd == 1) {
                ans = 0;
                cin >> u;
                for (auto i : v[u]) {
                    ans += vvv[i];
                }
                cout << ans << endl;
            } else {
                cin >> u >> vv;
                vvv[u] += vv;
            }
        }
    }
    return 0;
}