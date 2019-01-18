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
#define INF 0x3f3f3f3f
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
int a[100005],b[100005],sum1[100005],sum2[100005];
ll qmul(ll a, ll b, ll p = 998244353) { // return a*b %p
    ll t = 0;
    for (; b; a = a * 2 % p, b >>= 1) {
        if (b & 1) t = (t + a) % p;
    }
    return t;
}
ll qpow(ll a, ll b, ll p = 998244353) { // return a^b %p
    ll t = 1;
    for (a %= p; b; b >>= 1, a = qmul(a, a, p))
        if (b & 1) t = qmul(t, a, p);
    return t;
}
void stay(){
    cin >> n >> m;
    memset(a,0,sizeof a);
    memset(b,0,sizeof b);
    memset(sum1,0,sizeof sum1);
    memset(sum2,0,sizeof sum2);
    int x,y,z;
    REP(i,0,m){
        cin >> x >> y >> z;
        if (z == 2){
            a[x] += 1;
            a[y + 1] -= 1;
        }else{
            b[x] += 1;
            b[y + 1] -= 1;
        }
    }
    REP(i,1,n + 2){
        sum1[i] = sum1[i - 1] + a[i]; 
    }
    REP(i,1,n + 2){
        sum2[i] = sum2[i - 1] + b[i]; 
     }
     ll ans1 = INF;
     ll ans2 = INF;
     REP(i,1,n + 1){
         ans1 = min(ans1,(ll)sum1[i]);
         ans2 = min(ans2,(ll)sum2[i]);
     }
     //cout << ans1 << " " << ans2 << endl;
     cout << qmul(qpow(2,ans1),qpow(3,ans2)) << endl;
}
int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        stay();
    }
    return 0;
}
