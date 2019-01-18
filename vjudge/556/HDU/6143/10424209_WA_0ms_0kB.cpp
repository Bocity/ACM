#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); ++i)
#define PER(i, a, n) for (int i = (n) -1; i >= a; --i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int mid = 3000;
const int maxn = 2010;
inline int readT() {
    char c;
    int ret = 0, flag = 0;
    while (c = getchar(), (c < '0' || c > '9') && c != '-')
        ;
    if (c == '-')
        flag = 1;
    else
        ret = c ^ 48;
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c ^ 48);
    return flag ? -ret : ret;
}
int s[maxn][maxn];
int C[maxn][maxn];
int fac[maxn];
void init() {
    REP(p, 1, maxn) {
        s[p][0] = 0;
        REP(k, 1, p) {
            s[p][k] = ((ll) k * s[p - 1][k] + s[p - 1][k - 1]) % MOD;
        }
        s[p][p] = 1;
    }
    fac[0] = 1;
    REP(i, 1, maxn) {
        fac[i] = (ll) fac[i - 1] * i % MOD;
    }
    C[0][0] = 1;
    for (int i = 1; i < maxn; i++)
        for (int j = 0; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
}
int main() {
    int t, m, n;
    init();
    t = readT();
    while (t--) {
        n = readT();
        m = readT();
        ll ans = 0;
        REP(i, 1, n + 1) {
            if (m - i == 0) break;
            REP(j, 1, m - i + 1) {
                ans = (ans + ((ll) C[m][i] * fac[i] * s[n][i] % MOD) * ((ll) C[m - i][j] * fac[j] * s[n][j]) % MOD) % MOD;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}