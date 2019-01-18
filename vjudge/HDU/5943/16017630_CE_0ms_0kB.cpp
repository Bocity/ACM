#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n) -1; i >= x; --i)
#define endl "\n"
#define DE puts("----------")
#define CASE(i, ans) cout << "Case #" << (i) << ": " << (ans) << "\n"
#define lowbit(x) ((x) & (-(x)))
#define sqr(x) ((x) * (x))
#define eps 1e-9
#define PI acos(-1.0)
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
__gnu_pbds::cc_hash_table<string, int> hash1;
__gnu_pbds::gp_hash_table<string, int> hash2;
__gnu_pbds::priority_queue<int> pq;
__gnu_pbds::tree<int, null_type, less<int>, rb_tree_tag> rbtree;
typedef bitset<1005> Bitset;
const int maxn = 10005;
ll n, m, k;
const long long mod = 1000000007;
vector<int> v[maxn];
int cy[maxn];
bool vis[maxn];
bool check(int rt) {
    int sz = v[rt].size();
    for (int i = 0; i < sz; ++i) {
        int vv = v[rt][i];
        if (vis[vv]) continue;
        vis[vv] = true;
        if (cy[vv] == -1 || check(cy[vv])) {
            cy[vv] = rt;
            return true;
        }
    }
    return false;
}
int dfs(int n) {
    int ret = 0;
    memset(cy, -1, sizeof(cy));
    for (int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof(vis));
        ret += check(i);
    }
    return ret;
}

int main() {
    // ios::sync_with_stdio(0);
    int t;
    cin >> t;
    int cas = 0;
    int s, n;
    while (t--) {
        cas++;
        cin >> n >> s;
        if (n - s - 1 > 500 &&) {
            cout << "Case #" << cas << ": No" << endl;
            continue;
        }
        if ((s == 0 || s == 1)) {
            cout << "Case #" << cas << ": Yes" << endl;
            continue;
        }
        for (int i = 0; i < maxn; ++i) {
            v[i].clear();
        }
        bool flag = 1;
        // for (int i = 1; i <= n; ++i) {
        //     if (i % 2) {
        //         if ((s + n) / i - (s + 1) / i == 1) {
        //             if ((s + n) / i * i % 2 == 0) {
        //                 flag = 0;
        //                 break;
        //             }
        //         }
        //     }
        // }
        for (int i = s + 1; i <= s + n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i % j == 0) {
                    v[j].push_back(i - s + 2 * n);
                }
            }
        }
        int ans = dfs(n);
        if (ans < n) flag = 0;
        if (flag) {
            cout << "Case #" << cas << ": Yes" << endl;
        } else {
            cout << "Case #" << cas << ": No" << endl;
        }
    }
    return 0;
}
