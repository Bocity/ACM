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
ll p[100],e[100];
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
    cin >> m;
    REP(i,0,m){
        cin >> p[i] >> e[i];
    }
    ll ans = 1;
    REP(i,0,m){
       ans = qmul(ans,qmul(qpow(p[i],(e[i]-1)),(p[i]-1) * e[i] + p[i]));
    }
    cout << ans << endl;
}
int main() {
    int t;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        stay();
    }
    return 0;
}
