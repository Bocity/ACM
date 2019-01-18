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
int dpa[N], dpb[N];
int numa[N], numb[N];
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
        mems(numa, 0);
        mems(numb, 0);
        REP(i, 0, n) numb[i] = 1;
        REP(i, 1, n) {
            REP(j, 0, i) {
                if (a[i] > a[j]) {
                    if (dpa[i] < dpa[j] + 1) {
                        numa[i] = numa[j];
                        dpa[i] = dpa[j] + 1;
                    } else if (dpa[i] == dpa[j] + 1) {
                        numa[i] = min(numa[i], numa[j]);
                    }
                }
                if (a[i] > b[j]) {
                    if (dpa[i] < dpb[j] + 1) {
                        numa[i] = numb[j];
                        dpa[i] = dpb[j] + 1;
                    } else if (dpa[i] == dpb[j] + 1) {
                        numa[i] = min(numa[i], numb[j]);
                    }
                }
                if (b[i] > a[j]) {
                    if (dpb[i] < dpa[j] + 1) {
                        numb[i] = numa[j] + 1;
                        dpb[i] = dpa[j] + 1;
                    } else if (dpb[i] == dpa[j] + 1) {
                        numb[i] = min(numb[i], numa[j]) + 1;
                    }
                }
                if (b[i] > b[j]) {
                    if (dpb[i] < dpb[j] + 1) {
                        numb[i] = numb[j] + 1;
                        dpb[i] = dpb[j] + 1;
                    } else if (dpb[i] == dpb[j] + 1) {
                        numb[i] = min(numb[i], numb[j] + 1);
                    }
                }
            }
        }
        REP(i, 0, n) {
            if (numa[i] > m)
                ans = max(ans, dpa[i] + m - numa[i]);
            else
                ans = max(ans, dpa[i]);
            if (numb[i] > m)
                ans = max(ans, dpb[i] + m - numb[i]);
            else
                ans = max(ans, dpb[i]);
        }
        printf("%d\n", ans + 1);
    }
    return 0;
}