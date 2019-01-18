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
int main() {
    ios::sync_with_stdio(false);
    // freopen("test.txt", "r", stdin);
    int t, temp;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        REP(i, 0, n) {
            cin >> a[i] >> b[i];
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
        cout << ans + 1 << endl;
    }
    return 0;
}