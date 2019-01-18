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
const int maxn = 1005;
const long long mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, x[maxn];
    char c;
    cin >> t;
    while(t--) {
        int n, k;
        int l = -1, r = 1;
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> x[i];
        for(int i = 0; i < n; i++) {
            cin >> c;
            if(i == 0) continue;
            if(c == 'L') r += x[i];
            if(c == 'D') l -= x[i];
            if(c == 'N') l -= x[i], r += x[i];
        }
        if(k >= l && k <= r) cout << "yes" << endl;
        else cout << "no" <<endl;
    }
    return 0;
}