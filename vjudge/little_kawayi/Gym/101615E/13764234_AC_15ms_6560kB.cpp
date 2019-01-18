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
double l[100000],r[100000],v[100000],d[100000];
double X,Y,V;
main() {
    cin >> n >> X >> V;
    double ans = 0;
    REP(i,0,n){
        cin >> l[i] >> r[i] >> v[i];
        d[i] = r[i] - l[i];
        ans += d[i];
    }
    double anss = 0;
    REP(i,0,n){
        anss += d[i] * v[i];
    }
    double si = anss / (V * (X ));
    if (si > - 1 && si < 1 && X / (V * sqrt(1-si*si)) <= 2 * X / V)  {
        cout << setprecision(3)  << fixed <<  X / (V * sqrt(1-si*si)) << endl; 
    }else{
        puts("Too hard");
    }
    return 0;
}