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
#define base (int) 1e9
using namespace std;
typedef unsigned long long ll;
__gnu_pbds::cc_hash_table<ll, bool> hash1;
__gnu_pbds::cc_hash_table<ll, bool> hash2;
__gnu_pbds::priority_queue<int> pq;
__gnu_pbds::tree<int, null_type, less<int>, rb_tree_tag> rbtree;
typedef bitset<1005> Bitset;
const int maxn = 10005;
ll n, m, k;
const long long mod = 1000000007;
ll ans = 0;
vector <ll> q,q2;
main() {
    ll a,b;
    cin >> a >> b ;
    ll p = sqrt(b) + 0.5;
    REP(i,1,p+1){
        if (!hash1[i])
        q.push_back(i);
        hash1[i] = true;
        if (!hash1[b/i])
        q.push_back(b/i);
        hash1[b/i] = true;
    }
    // for(auto &i:q){
    //     ll l = b/ (i + 1) + 1, r = b / i;
    //     ans += i * (r - l + 1) * (l + r) / 2;
    // }
    //cout << ans << endl;
    a--;
    p = sqrt(a) + 0.5;
    REP(i,1,p+1){
        if (!hash2[i])
        q2.push_back(i);
        hash2[i] = true;
        if (!hash2[a/i])
        q2.push_back(a/i);
        hash2[a/i] = true;
    }
    ll dd = q2.size();
    ll i ;
    REP(j,0,dd){
        i = q2[j];
        ll l = a / (i + 1) + 1, r = a / i;
        ans -= i * (r - l + 1) * (l + r) / 2;
        i = q[j];
        l = b/ (i + 1) + 1, r = b / i;
        ans += i * (r - l + 1) * (l + r) / 2;
    }
    ll ddd = q.size();
    REP(j,dd,ddd){
        i = q[j];
        ll l = b/ (i + 1) + 1, r = b / i;
        ans += i * (r - l + 1) * (l + r) / 2;
    }
    cout << ans << endl ;
    return 0;
}