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
const int maxn = 1000 + 10;
int n, m, s, ans;
struct node {
    int t;
    int nxt;
}edge[maxn];
int head[maxn], nxtt[25];
int mp[maxn][maxn];
void addEdge(int num, int u, int v) {
    edge[num].t = v;
    edge[num].nxt = head[u];
    head[u] = num;
}
void dfs(int now, int dep) {
    if(now == s) {
        ans++;
        return ;
    }
    for(int i = head[dep]; i != -1; i = edge[i].nxt) {
        int t = edge[i].t;
        bool flag = true;
        for(int j = 0; j < now; j++) {
            if(!mp[nxtt[j]][t]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            nxtt[now] = t;
            dfs(now + 1, t);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int x, y;
        ans = 0;
        cin >> n >> m >> s;
        mem(head, -1);
        mem(mp, 0);
        for(int i = 0; i < m; i++) {
            cin >> x >> y;
            if(x > y) swap(x, y);
            addEdge(i, x, y);
            mp[x][y] = mp[y][x] = 1;
        }
        for(int i = 1; i <= n; i++) {
            nxtt[0] = i;
            dfs(1, i);
        }
        cout << ans << endl;
    }
    return 0;
}
