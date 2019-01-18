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
#define pii pair<int,int>
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
__gnu_pbds::cc_hash_table<string, int> hash1;
__gnu_pbds::gp_hash_table<string, int> hash2;
__gnu_pbds::priority_queue<int> pq;
__gnu_pbds::tree<int, null_type, less<int>, rb_tree_tag> rbtree;
const int maxn = 10005;
ll n, m, k;
const long long mod = 1000000007;
int fuck[maxn];
int a[maxn];
vector<pii> v[maxn];
ll calc(){
    ll anss = 0;
    REP(i,0,k - 1){
        int from = a[i];
        int to = a[i + 1];
        int ans = 0x3f3f3f;
        int sz = v[from].size();
        REP(j,0,sz){
            if (v[from][j].first == to){
                ans = min(ans,v[from][j].second);
            }
        }
        anss += ans;
        //cout << from << " " << to << " " << ans << endl;
    }
    return anss;
}
bool Fuck(int ans){
    
}
int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    REP(i,0,k){
        cin >> a[i];
    }
    REP(i,0,m){
        int  a,b,c;
        cin >> a >> b >> c;
        v[a].push_back(pii(b,c));
        v[b].push_back(pii(a,c));
    }
    int ans = calc();
    cout << (ans % 2?"yes":"no") << endl;
    return 0;
}
