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
const int maxn = 100005;
ll n, m, k;
const long long mod = 1000000007;
int minians = 0;
int a[maxn];
int vis[maxn];
int viss[maxn];
int main() {
    ios::sync_with_stdio(0);
    while(cin >> n){
        memset(vis,0,sizeof vis);
        memset(viss,0,sizeof viss);
        REP(i,1,n + 1){
            cin >> a[i];
        }
        long long  anss = 0;
        int pos;
        int ans2;
        REP(fi,1,n + 1){
            int sz = sqrt(a[fi]) + 1;
            int mini = 0;
            REP(ai,1,sz){
                if (a[fi] % ai == 0 && vis[ai]){
                   if (!viss[vis[ai]]){
                       viss[vis[ai]] = 1;
                        anss += fi;
                   }
                }
                if (a[fi] % ai == 0){
                    int aii = a[fi] / ai;
                    if (vis[aii]  && !viss[vis[aii]]){
                            viss[vis[aii]] = 1;
                            anss += fi;
                        }
                }
            }
            vis[a[fi]] = fi;
        }
        cout << anss << endl;
    }
    return 0;
}

// 8 1 5 50 6 100 4 3 10
// 10 2 4 6 8 10 12 14 16 18 20