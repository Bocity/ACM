#include <bits/stdc++.h>
#define endl "\n"
#define REP(x, n) for (int x = 0; x < (n); x++)
#define MAXN 100007
#define MOD 1000000007
using namespace std;
typedef long long ll;
int read() {
    int n = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return n * f;
}
bool vis[MAXN] = {0};
int cal1[MAXN], cal2[MAXN];
int a[MAXN], b[MAXN], n, m;
void dfs(int x, int n) {
    if (vis[x]) {
        cal1[n]++;
        return;
    }
    vis[x] = true;
    dfs(a[x], n + 1);
}
void dfs2(int x, int n) {
    if (vis[x]) {
        cal2[n]++;
        return;
    }
    vis[x] = true;
    dfs2(b[x], n + 1);
}
ll ans, ret;
int main() {
    ios::sync_with_stdio(0);
    int cas = 0;
    while (cin >> n >> m) {
        ans = 1;
        memset(cal1, 0, sizeof cal1);
        memset(cal2, 0, sizeof cal2);
        memset(vis, 0, sizeof vis);
        REP(i, n) {
            // a[i] = read();
            cin >> a[i];
        }
        REP(i, m) {
            //  b[i] = read();
            cin >> b[i];
        }
        REP(i, n) {
            if (!vis[i]) {
                dfs(i, 0);
            }
        }
        memset(vis, 0, sizeof vis);
        REP(i, m) {
            if (!vis[i]) {
                dfs2(i, 0);
            }
        }
        REP(i, n + 1) {
            if (i != 0 && cal1[i]) {
                ret = 0;
                int mid = sqrt(i + 0.5);
                REP(j, mid + 1) {
                    if (j != 0 && i % j == 0) {
                        ret += (ll)(j % MOD) * (ll)(cal2[j] % MOD) % MOD;
                        if (j * j != i) {
                            ret += (ll)(i / j % MOD) * (ll)(cal2[i / j] % MOD) % MOD;
                        }
                    }
                }
                REP(j, cal1[i]) {
                    ans = ans * ret;
                }
            }
        }
        cout << "Case #" << ++cas << ": " << ans << endl;
    }
    return 0;
}