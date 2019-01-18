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
inline int read() {
    char c;
    int ret = 0, flag = 0;
    while (c = getchar(), (c < '0' || c > '9') && c != '-')
        ;
    if (c == '-')
        flag = 1;
    else
        ret = c ^ 48;
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c ^ 48);
    return flag ? -ret : ret;
}
int main() {
    long long T, n, m, a, b, q, u, vv, cmd, ans;
    ios::sync_with_stdio(false);
    T = read();
    while (T--) {
        for (int i = 0; i < 100010; i++) v[i].clear();
        mems(vvv, 0);
        ans = 0;
        n = read();
        m = read();
        for (int i = 1; i <= m; i++) {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        q = read();
        for (int i = 0; i < q; i++) {
            cmd = read();
            if (cmd == 1) {
                ans = 0;
                u = read();
                for (auto i : v[u]) {
                    ans += vvv[i];
                }
                cout << ans << endl;
            } else {
                u = read();
                vv = read();
                vvv[u] += vv;
            }
        }
    }
    return 0;
}