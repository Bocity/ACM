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
typedef pair<int, vector<int>> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 1100;
int a[N], b[N];
int dpa[N][N];
int dpb[N][N];
int n, m;
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
    // freopen("test.txt", "r", stdin);
    int t, temp;
    t = readT();
    while (t--) {
        n = readT();
        m = readT();
        REP(i, 0, n) {
            a[i] = readT();
            b[i] = readT();
        }
        int ans = 0;
        mems(dpa, 0);
        mems(dpb, 0);
        REP(i, 0, n) {
            REP(j, 0, i) {
                REP(k, 0, j + 1) {
                    if (k > m) break;
                    if (a[j] < a[i]) {
                        dpa[i][k] = max(dpa[j][k] + 1, dpa[i][k]);
                    }
                    if (b[j] < a[i]) {
                        dpa[i][k] = max(dpb[j][k] + 1, dpa[i][k]);
                    }
                    ans = max(dpa[i][k], ans);
                    if (k + 1 > m) continue;
                    if (a[j] < b[i]) {
                        dpb[i][k + 1] = max(dpa[j][k] + 1, dpb[i][k + 1]);
                    }
                    if (b[j] < b[i]) {
                        dpb[i][k + 1] = max(dpb[j][k] + 1, dpb[i][k + 1]);
                    }
                    ans = max(dpb[i][k + 1], ans);
                }
            }
        }
        printf("%d\n", ans + 1);
    }
    return 0;
}