#include <bits/stdc++.h>
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
#define N 20005
#define Maxn 20005
using namespace std;
typedef long long ll;
const int maxn = 20005;
const long long mod = 1000000007;
int g[1010][1010], p[Maxn / 10], tot, d[Maxn], n, m, A[Maxn], B[Maxn], C[Maxn];
bool vis[Maxn];
inline void init(int n) {
    for (int i = 0; i <= 1005; i++)
        for (int j = 0; j <= i; j++) {
            if (!i || !j)
                g[i][j] = i + j;
            else
                g[i][j] = g[j][i % j];
        }
    for (int i = 0; i <= 1005; i++)
        for (int j = i + 1; j <= 1005; j++) g[i][j] = g[j][i];
    d[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            p[++tot] = i;
            d[i] = i;
        }
        for (int j = 1; j <= tot; j++) {
            if (i * p[j] > n) break;
            vis[i * p[j]] = 1;
            if (i % p[j] == 0) {
                d[i * p[j]] = d[i];
                break;
            }
            d[i * p[j]] = p[j];
        }
    }
    A[1] = B[1] = C[1] = 1;
    for (int i = 2; i <= n; i++) {
        int j = i / d[i];
        A[i] = A[j], B[i] = B[j], C[i] = C[j];
        if (A[i] * d[i] <= 1000)
            A[i] *= d[i];
        else if (B[i] * d[i] <= 1000)
            B[i] *= d[i];
        else
            C[i] *= d[i];
    }
}
int X[3], c;
inline int gcd(int a, int b) {
    if (!a || !b) return a + b;
    if (a <= 1000 && b <= 1000) return g[a][b];
    c = 0;
    int ans = 1, d = 1;
    if (A[a] != 1) X[c++] = A[a];
    if (B[a] != 1) X[c++] = B[a];
    if (C[a] != 1) X[c++] = C[a];
    for (int i = 0; i < c; i++) {
        if (X[i] <= 1000)
            d = g[X[i]][b % X[i]];
        else if (b % X[i] == 0)
            d = X[i];
        else
            d = 1;
        ans *= d;
        b /= d;
    }
    return ans;
}
int a[N];
long viss[N];
bool visss[N];
main() {
    ios::sync_with_stdio(0);
    init(10005);
    while (cin >> n) {
        memset(viss,0,sizeof viss);
        REP(i, 1, n + 1) {
            cin >> a[i];
        }
        long long res = 0;
        int t = 0;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j < i; ++j){
                t = gcd(a[i], a[j]);
                res += sqr(t) - t;
            }
        }
        res = res * 2 % 10007;
        for(int i = 1; i <=n; ++i){
            res += (sqr(a[i])-a[i]);
        }
        cout << res % 10007 << endl;
    }
    return 0;
}