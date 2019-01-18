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
ll n, m, k;
const long long mod = 1000000007;
// int a[10000];
struct node {
    int a, b, i;
} s[4000];
bool cmp(node x, node y) {
    if (x.a == y.a) {
        return x.b < y.b;
    }
    return x.a < y.a;
}
int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        REP(i, 0, 3 * n) {
            cin >> s[i].a >> s[i].b;
            s[i].i = i + 1;
        }
        sort(s, s + 3 * n, cmp);
        for (int i = 0; i < 3 * n; i += 3) {
            cout << s[i].i << " " << s[i + 1].i << " " << s[i + 2].i << endl;
        }
    }

    return 0;
}