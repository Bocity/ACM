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
int n, m, k , w , h ,c;
const long long mod = 1000000007;
vector<int> v[maxn];
int vis[maxn];
int vis2[maxn];
int dfs(int rt,int dep){
    if (dep < vis2[rt]) return vis2[rt];
    int sz = v[rt].size();
    int ans = dep;
    vis[rt] = 1;
    vis2[rt] = dep;
    REP(i,0,sz){
        if (!vis[i]){
            ans = max(dfs(v[rt][i],dep + 1),ans);
        }
    }
    vis[rt] = 0;
    return ans;
}
bool check(int rt){
    int sz = v[rt].size();
    vis[rt] = 1;
    if (vis[rt] )return 1;
    bool flag = 0;
    REP(i,0,sz){
        if (!vis[i]){
            flag |= check(i);
            if (flag) return 1;
        }
    }
    vis[rt] = 0;
    return flag;
}
int r[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    REP(i,0,n){
        cin >> k;
        REP(j,0,k){
            int x;
            cin >> x;
            v[x].push_back(i);
            r[i]++;
           // cout << j << " " << r[j] << endl;
        }
    }
    int ans = 0;
    REP(i,0,n){
        if (r[i] == 0 && !vis2[i] && check(i)){
            ans += (dfs(i,1) - 1);
            //cout << ans << " " << i <<" "  <<r[i] <<endl;;
        }
    }
    cout << ans << endl;
}