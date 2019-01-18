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
const int maxn = 200005;
ll l, r, x, y, k, m, n;
const long long mod = 1000000007;
vector<ll> q;
ll pd[maxn];
ll sum[maxn];
int main() {
    ios::sync_with_stdio(0);
    cin >> n >> k;
    REP(i, 0, n) {
        cin >> m;
        q.push_back(m);
    }
    int i = 0, j = 0;
    ll ans = 1;
    ll tmp = 1;
    ll sum = q[0];
    int anss = 0;
    while (i <= j && j < n) {
        if (ans >= k) {
            if (ans == k) {
                anss++;
            }
            ++i;
            tmp /= q[i];
            if (sum == q[i]) break;
            ans = tmp * sum / (sum - q[i]);
            sum -= q[i];
        } else {
            ++j;
            while (tmp * q[j] * sum % (sum + q[j]) != 0) {
                ans = tmp * q[j] * sum / (sum + q[j]);
                if (ans > k) break;
                sum += q[j];
                tmp *= q[j];
                j++;
            }
            ans = tmp * q[j] * sum / (sum + q[j]);
            sum += q[j];
            tmp *= q[j];
        }
    }
    cout << anss << endl;
    return 0;
}