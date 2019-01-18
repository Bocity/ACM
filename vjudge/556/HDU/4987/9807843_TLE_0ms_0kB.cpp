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
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 600000;
const double eps = 1e-10;
double dp[maxn];
double sum[maxn];
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
int main() {
    int n, m;
    while (m = readT()) {
        n = readT();
        if (m >= n) {
            cout << fixed << setprecision(5) << pow(1 + 1.0 / m, n - 1) / m << endl;
        } else {
            bool flag = false;
            dp[0] = sum[0] = 1;
            REP(i, 1, n + 1) {
                dp[i] = (sum[i - 1] - (i - 1 - m > -1 ? sum[i - 1 - m] : 0)) / m;
                if (fabs(dp[i - 1] - dp[i]) < eps) {
                    printf("%.5f\n", dp[i]);
                    flag = true;
                    break;
                }
                sum[i] = sum[i - 1] + dp[i];
            }
            if (!flag) printf("%.5f\n", dp[n]);
        }
    }
    return 0;
}