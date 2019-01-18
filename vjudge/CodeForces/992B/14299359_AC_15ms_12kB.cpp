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
typedef unsigned long long ll;
__gnu_pbds::cc_hash_table<string, int> hash1;
__gnu_pbds::gp_hash_table<string, int> hash2;
__gnu_pbds::priority_queue<int> pq;
__gnu_pbds::tree<int, null_type, less<int>, rb_tree_tag> rbtree;
typedef bitset<1005> Bitset;
const int maxn = 10005;
ll l, r, x, y;
const long long mod = 1000000007;
int main() {
    ios::sync_with_stdio(0);
    cin >> l >> r >> x >> y;
    if (y % x != 0) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    ll tmp = y / x;
    ll p = sqrt(tmp);
    for (ll i = 1; i <= p; ++i) {
        if (tmp % i == 0) {
            if (x * tmp / i >= l && x * tmp / i <= r && i * x >= l && i * x <= r && __gcd(tmp / i, (ll) i) == 1)
                if (tmp / i == i)
                    ans++;
                else {
                    ans += 2;
                }
        }
    }
    cout << ans << endl;
    return 0;
}
// fuck