#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n) - 1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-5
#define PI acos(-1.0)
#define mem(a, b) memset(a, b, sizeof a)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const ll mod = 1e9 + 7;
const int maxn = 100 + 10;
int n, s, m;
int mp[maxn][maxn], ans, vis[maxn];
int dfs(int u, int v) {
    for(int i = 0; i <= n; i++) {
        if(mp[u][i] && !vis[i] && i != v) {
            ans++;
            vis[i] = 1;
            dfs(i, v);
            vis[i] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int u, v, aa;
    while(cin >> n && n) {
        mem(mp, 0);
        mem(vis, 0);
        ans = 0;
        cin >> s >> m;
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            mp[u][v] = 1;
            mp[v][u] = 1;
        }
        int tmp = inf;
        for(int i = 1; i <= n; i++) {
            ans = 0;
            if(i != s) {
                dfs(s, i);
                if(ans < tmp) {
                    tmp = ans;
                    aa = i;
                }
            }
        }
        cout << aa << endl;
    }
    return 0;
}