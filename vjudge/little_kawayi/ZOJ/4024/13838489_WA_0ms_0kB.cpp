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
const int INF = 0x3f3f3f3f;
ll n, m, k;
const long long mod = 1000000007;
int t;
ll a[100005];
int main() {
    cin >> t;
    while(t--){
        cin >> n;
        REP(i,0,n){
            cin >> a[i];
        }
        bool flag = false;
        bool flag2 = false;
        int pos = 0;
        REP(i,1,n){
            if (a[i] <= a[i - 1]){
                pos = i;
                //flag = true;
                break;
            }
        }
        if (pos == 1 || pos == 0 || (pos == n - 1 && a[pos] == a[pos - 1])){
            puts("NO");
            continue;
        }
        REP(i,pos,n){
            if (a[i] > a[i - 1] || (a[i] == a[i-1] && i != pos) ){
                puts("No");
                flag2 = true;
                break;
            }
        }
        if (!flag2){
            puts("Yes");
        }
    }
    return 0;
}

