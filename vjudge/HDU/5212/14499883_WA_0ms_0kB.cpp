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
int a[20005];
int f[20005];
int vis[20005];
int main() {
    ios::sync_with_stdio(0);
    while(cin >> n){
        memset(f,0,sizeof f);
        memset(vis,0,sizeof vis);
        REP(i,0,n){
            cin >> a[i];
            vis[a[i]] ++;
        }
        PER(i,1,10005){
            for(int j = i; j < 10005; j+=i){
                f[i] += vis[j];
                f[i] -= (j == i)?0:f[j];
                f[i] %= 10007;
            }
        }
        ll ans = 0;
        REP(i,1,10005){
            if (f[i] !=0 ) cout << f[i] << " " << i << endl;
            ans += f[i] * (i) * (i - 1) % 10007;
        }
        cout << ans * 2 % 10007 << endl;
    }
    return 0;
}
//i * (i - 1)
//f[i] -= f[j]
