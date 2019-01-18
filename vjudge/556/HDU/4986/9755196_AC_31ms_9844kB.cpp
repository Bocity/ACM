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
const int maxn = 1000000;
double f[maxn];
const double r = 0.577215664901;
int main() {
    ios::sync_with_stdio(false);
    ll n;
    double ans = 0;
    REP(i, 1, maxn) {
        ans += 1.0 / i;
        f[i] = ans;
    }
    while (cin >> n) {
        if (n >= maxn) {
            // cout << fixed << setprecision(4) << f[n] << endl;
            cout << fixed << setprecision(4) << log(n + 1.0) + r << endl;
        } else {
            cout << fixed << setprecision(4) << f[n] << endl;
        }
    }
    return 0;
}