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
#define N 100005
#define Maxn 100005
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
__gnu_pbds::cc_hash_table<string, int> hash1;
__gnu_pbds::gp_hash_table<string, int> hash2;
__gnu_pbds::priority_queue<int> pq;
__gnu_pbds::tree<int, null_type, less<int>, rb_tree_tag> rbtree;
typedef bitset<1005> Bitset;
const int maxn = 100005;
const long long mod = 1000000007;
ll a[N];
ll x;
int doo(int ans,int i,int l,int r){
    //cout << ans <<" "<< i  << endl;
    if (i == 0) return ans;
    //cout << "WTF" << (x >> i) << endl;
    if (((x >> i) & 1) == 0){
        //cout << "fuck" << i << endl;
        if (ans + (1 << (i - 1)) - 1>= l  && ans <= r)
        return doo(ans,i - 1,l,r);
        ans += (1 << (i -1));
        return doo(ans,i - 1,l,r);
    }else{
        //cout << "stay" << endl;
        ans += (1 << (i -1));
        if (ans + (1 << (i - 1)) - 1>= l && ans <= r)
        return doo(ans,i - 1,l,r);
        ans -= (1 << (i -1));
        return doo(ans,i - 1,l,r);
    }
}
// 100
// 011
// 001
// 0
int ans = 0;
ll stay(){
    ll l1,l2,r1,r2;
    ans = 0;
    cin >> l1 >> r1 >> l2 >> r2;
    for(ll i = l1 ; i <= l2 ;++ i){
        x = i;
        ans = min(ans,x^doo(0,31,3,8));
    }
    return ans;
}
main() {
    ios::sync_with_stdio(0);
    int t;
    x = 3;
    cout << (x^doo(0,31,3,8));
    // for(int i = 1; i < 4; ++i){
    //     for(int j = 4; j < 8; ++j){
    //         cout << "(" << i << "," << j << ")" << (i^j) << endl;
    //     }
    // }
    cin >> t;
    int cases = 0;
    while(t--){
        cases ++;
        cout << "Case #" << cases << ": " << stay() << endl;
    }
    return 0;
}