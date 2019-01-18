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
#define N 100010 // range to screen
const double eps = 1e-8;
int prime[N];
bool vis[N] = {true, true};
int tot = 0;
void screen() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) prime[tot++] = i;
        for (int j = 0; j < tot && (ll) i * prime[j] < N; j++) {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}
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
double a, b, c, d, L, R;
double fuck(double x) {
    return fabs(a * x * x * x + b * x * x + c * x + d);
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    int n;
    while (cin >> a >> b >> c >> d >> L >> R) {
        double ans = 0;
        if (a == 0 && b != 0 && c * c >= 4 * b * d) {
            double ji1 = -c / (2 * b);
            if (ji1 <= R && ji1 >= L) ans = max(ans, fuck(ji1));
        }
        if (a != 0 && b * b >= 3 * a * c) {
            double ji1 = (-2 * b + 2 * sqrt(b * b - 3 * a * c)) / (6 * a);
            double ji2 = (-2 * b - 2 * sqrt(b * b - 3 * a * c)) / (6 * a);
            if (ji1 <= R && ji1 >= L) ans = max(ans, fuck(ji1));
            if (ji2 <= R && ji2 >= L) ans = max(ans, fuck(ji2));
        }
        ans = max(ans, fuck(L));
        ans = max(ans, fuck(R));
        cout << fixed << setprecision(2) << ans << endl;
    }
    return 0;
}