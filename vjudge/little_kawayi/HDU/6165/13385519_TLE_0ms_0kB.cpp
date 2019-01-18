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
#define mems(a,x) memset(a,x,sizeof a)
#define PI acos(-1.0)
#define N 6000
#define M 7000
#define MOD 1000000007
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
__gnu_pbds::cc_hash_table<string, int> hash1;
__gnu_pbds::gp_hash_table<string, int> hash2;
__gnu_pbds::priority_queue<int> pq;
__gnu_pbds::tree<int, null_type, less<int>, rb_tree_tag> rbtree;
typedef bitset<1005> Bitset;
bool viss[5005][5005]{0};
const int maxn = 10000005;
ll n, m, k;
const long long mod = 1000000007;
struct arc {
    int x, f, next;
};
struct spfa {
    int pre[N], mcnt, s, dis[N];
    bool vis[N];
    arc e[2 * M];
    void init(int i) {
        mems(pre, -1);
        mcnt = 0;
        s = i;
    }
    void setting(int i){
        s = i;
    }
    void addarc(int x, int y, int z) {
        e[mcnt] = (arc){y, z, pre[x]}, pre[x] = mcnt++;
        //e[mcnt] = (arc){x, z, pre[y]}, pre[y] = mcnt++;
    }
    void go() {
        queue<int> q;
        REP(i,0,N){
            dis[i] = 10000005;
        }
        mems(vis, false);
        dis[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vis[u] = false;
            for (int i = pre[u]; ~i; i = e[i].next) {
                int v = e[i].x, c = e[i].f;
                if (dis[v] > dis[u] + c) {
                    dis[v] = dis[u] + c;
                    if (!vis[v]) vis[v] = true, q.push(v);
                }
            }
        }
    }
    bool check(int i){
        if (dis[i] == 10000005) return false;
        return true;
    }
}SP;
int T;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n ,m,x, y;
    cin >> T;
    while(T--){
        cin >> n >> m;
        mems(viss,0);
        SP.init(1);
        REP(i,0,m){
            cin >> x >> y;
            SP.addarc(x,y,1);
        }
        bool flag  =false;
        REP(i,1,n+1){
            SP.setting(i);
            SP.go();
            REP(j,1,n+1){
                if (SP.check(j)){
                    viss[j][i]= true;
                }
            }
        }
        REP(i,1,n+1){
            REP(j,i+1,n+1){
                if (!viss[i][j] && !viss[j][i]){
                    flag = true;
                    break;
                }
            }
        }
        if (flag){
            cout << "Light my fire!" << endl;
        }else{
            cout << "I love you my love and our love save us!" << endl;
        }
    }
    return 0;
}
