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
typedef pair<int,int> pii;
int x,y,z;
int a[90005],b[90005],c[90005],ss[1000][1000];
void stay(){
    cin >> m;
    int n = m*(m-1)/2;
    REP(i,0,n){
        cin >> a[i] >> b[i] >> c[i];
        ss[a[i]][b[i]] = c[i];
        ss[b[i]][a[i]] = c[i];
    }

    int ans = 0;
    REP(i,0,n){
        REP(j,1,m + 1){
            if (j != a[i] && j != b[i])
            ans = max(ans,ss[a[i]][j] + ss[j][b[i]] + c[i]);
            ans = max(ans,ss[b[i]][j] + ss[j][a[i]] + c[i]);
        }
    }
    cout << ans << endl;
    // int anss = 0;
    // REP(i,0,n){
    //     if (vis[a[i]][b[i]] + c[i] == ans)
    //     vis[a[i]][b[i]] + c[i];
    // }
    // cout << anss << endl;
}
int main() {
    int t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        stay();
    }
    return 0;
}

