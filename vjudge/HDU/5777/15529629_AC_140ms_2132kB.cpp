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
const int maxn = 100050;
ll n, m, k, sum;
const long long mod = 100000007;
ll a[maxn];
int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        sum = 0;
        cin >> n >> k;
        REP(i, 0, n - 1) {
            cin >> a[i];
            sum += a[i];
        }
        if (k >= n){
            cout << n << endl;
            continue;
        }
        sort(a, a + n - 1, greater<int>());
        REP(i, 0, k - 1) {
            sum -= a[i];
        }
        cout << sum + n << endl;
    }
    return 0;
}
