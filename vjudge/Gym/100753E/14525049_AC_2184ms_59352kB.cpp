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
#define pii pair<int, int>
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
__gnu_pbds::cc_hash_table<string, int> hash1;
__gnu_pbds::gp_hash_table<string, int> hash2;
__gnu_pbds::priority_queue<int> pq;
__gnu_pbds::tree<int, null_type, less<int>, rb_tree_tag> rbtree;
const int maxn = 10005;
const long long mod = 1000000007;
struct arr {
    int nd, nx, co;
} bot[2500000];
int k;
int head[1500000], SF[1500000], f[1500000], dist[1500000], vis[1500000],a[150000];
int n, m, cnt;
inline void add(int a, int b, int c) {
    bot[++cnt].nd = b;
    bot[cnt].nx = head[a];
    bot[cnt].co = c;
    head[a] = cnt;
}
inline void SPFA(int s) {
    deque<int> q;
    for (register int i = 1; i <= n; ++i) dist[i] = 0x3f3f3f3f, vis[i] = 0;
    dist[s] = 0;
    vis[s] = 1;
    q.push_back(s);
    while (!q.empty()) {
        int u = q.front();
        int v;
        q.pop_front();
        vis[u] = 0;
        for (register int i = head[u]; i; i = bot[i].nx) {
            if (dist[v = bot[i].nd] == dist[u] + bot[i].co) {
                if (vis[v])
                    f[v] += f[u], f[v] %= mod;
                else
                    f[v] = f[u];
                SF[v] += SF[u];
                SF[v] %= mod;
            }
            if (dist[v = bot[i].nd] > dist[u] + bot[i].co) {
                dist[v] = dist[u] + bot[i].co;
                f[v] = f[u];
                SF[v] = SF[u];
                if (!vis[v]) {
                    vis[v] = 1;
                    if (q.empty() || dist[v] > dist[q.front()])
                        q.push_back(v);
                    else
                        q.push_front(v);
                }
            }
        }
    }
}
int main() {
ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    REP(i,0,k){
        cin >> a[i];
    }
    REP(i,0,m){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
        add(b,a,c);
    }
    f[1] = 1;
    SF[1] = 1;
    SPFA(1);
    int ans = SF[n];
    cout << ((ans > 1) ? "yes":"no") << endl;
}