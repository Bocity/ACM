#include <algorithm>
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
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
namespace fastIO {
#define BUF_SIZE 100000
// fread -> read
bool IOerror = 0;
inline char nc() {
    static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
    if (p1 == pend) {
        p1 = buf;
        pend = buf + fread(buf, 1, BUF_SIZE, stdin);
        if (pend == p1) {
            IOerror = 1;
            return -1;
        }
    }
    return *p1++;
}
inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline bool read(int &x) {
    char ch;
    while (blank(ch = nc()))
        ;
    if (IOerror) return false;
    for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0')
        ;
    return true;
}
inline bool read(int &x, int &y) {
    return read(x), read(y);
}
#undef BUF_SIZE
};
// C(m, n)
const int maxn = 60;
int C[maxn][maxn];
void init() {
    C[0][0] = 1;
    for (int i = 1; i < maxn; i++) {
        for (int j = 0; j <= i; j++) {
            C[i][j] = ((ll) C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}
using namespace fastIO;
ll dp[maxn][maxn];
int main() {
    int n, m;
    init();
    while (read(n, m)) {
        if (n == 0 || m == 0) {
            puts("0");
            continue;
        }
        mems(dp, 0);
        dp[0][0] = 1;
        REP(i, 0, n + 1) {
            REP(j, 0, m + 1) {
                REP(k, 1, m + 1) {
                    REP(t, 0, k + 1) {
                        dp[i + 1][j + t] += dp[i][j] * C[m - j][t] * C[j][k - t] % MOD;
                        dp[i + 1][j + t] %= MOD;
                    }
                }
            }
        }
        printf("%lld\n", dp[n][m] % MOD);
    }
    return 0;
}