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
int a[10000];
int b[10000];
typedef unsigned long long ull;
int main() {
    ios::sync_with_stdio(0);
    REP(i, 0, 8) {
        cin >> b[i];
    }
    REP(i, 0, 8) {
        cin >> a[i];
    }
    bool flag = 0;
    int max1 = 0; // max2 = 0, max3 = 0, max4 = 0;
    for (int p = 1; p <= 2; ++p) {
        int tmp1, tmp2;
        for (int i = 0; i < 8; i += 2) {
            int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
            for (int j = 0; j < 8; j += 2) {
                ans1 += (a[i] <= b[j] && a[i + 1] <= b[j + 1]);
                ans2 += (a[i] >= b[j] && a[i + 1] <= b[j + 1]);
                ans3 += (a[i] <= b[j] && a[i + 1] >= b[j + 1]);
                ans4 += (a[i] >= b[j] && a[i + 1] >= b[j + 1]);
            }
            // cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << endl;
            flag |= (ans1 == 1 && ans2 == 1 && ans3 == 1 && ans4 == 1);
            tmp1 = a[i] - a[i + 1], tmp2 = a[i] + a[i + 1];
            a[i] = tmp1, a[i + 1] = tmp2;
        }
        for (int i = 0; i < 8; i += 2) {
            tmp1 = b[i] - b[i + 1], tmp2 = b[i] + b[i + 1];
            b[i] = tmp1, b[i + 1] = tmp2;
        }
        REP(i,0,8){
            swap(a[i],b[i]);
        }
    }

    cout << ((flag || max1 == 16) ? "YES" : "NO") << endl;
    return 0;
}
