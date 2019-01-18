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
bool stay(){
    ll x[10],y[10],z[10];
    REP(i,0,4){
        cin >> x[i] >> y[i] >> z[i];
    }
    ll l1,l2,l3,l4,l5,l6,l7;
    l1 = sqr(x[2] - x[0]) + sqr(y[2] - y[0]) + sqr(z[2] - z[0]);
    l2 = sqr(x[1] - x[0]) + sqr(y[1] - y[0]) + sqr(z[1] - z[0]);
    l3 = sqr(x[2] - x[1]) + sqr(y[2] - y[1]) + sqr(z[2] - z[1]);
    if (l1 != l2 && l2 != l3 && l3 != l1) return false;
    if (l1 == l2){
        if (l1 + l2 != l3 ) return false;
        l4  = sqr(x[3] - x[1]) + sqr(y[3] - y[1]) + sqr(z[3] - z[1]);
        l5  = sqr(x[3] - x[2]) + sqr(y[3] - y[2]) + sqr(z[3] - z[2]);
        l6  = sqr(x[3] - x[0]) + sqr(y[3] - y[0]) + sqr(z[3] - z[0]);
        if (l4 == l5 && l6 == l3) return true;
       // if (x[3] + x[0] == x[2] + x[1] && y[3] + y[0] == y[2] + y[1] && z[3] + z[0] == z[2] + z[1] ) return true;
    }else if(l1 == l3){
        if (l1 + l3 != l2) return false;
        l4  = sqr(x[3] - x[0]) + sqr(y[3] - y[0]) + sqr(z[3] - z[0]);
        l5  = sqr(x[3] - x[1]) + sqr(y[3] - y[1]) + sqr(z[3] - z[1]);
        l6  = sqr(x[3] - x[2]) + sqr(y[3] - y[2]) + sqr(z[3] - z[2]);
        if (l4 == l5 && l6 == l2) return true;
        //if (x[3] + x[0] == x[2] + x[1] && y[3] + y[0] == y[2] + y[1] && z[3] + z[0] == z[2] + z[1] ) return true;
    }else{
        if (l2 + l3 != l1) return false;
        l4  = sqr(x[3] - x[0]) + sqr(y[3] - y[0]) + sqr(z[3] - z[0]);
        l5  = sqr(x[3] - x[2]) + sqr(y[3] - y[2]) + sqr(z[3] - z[2]);
        l6  = sqr(x[3] - x[1]) + sqr(y[3] - y[1]) + sqr(z[3] - z[1]);
        if (l4 == l5 && l6 == l1) return true;
        //if (x[3] + x[0] == x[2] + x[1] && y[3] + y[0] == y[2] + y[1] && z[3] + z[0] == z[2] + z[1] ) return true;
    }
    return false;
}
main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    int cases = 0;
    while(t--){
        cases ++;
        cout << "Case #" << cases << ": " << (stay()?"Yes":"No") << endl;
    }
    return 0;
}