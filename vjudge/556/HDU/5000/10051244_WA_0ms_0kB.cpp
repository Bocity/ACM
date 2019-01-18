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
#include <sstream>
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
const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAXN = 3000;
int ar[MAXN];
int inv[MAXN];

int main() {
    ios::sync_with_stdio(false);
    inv[1] = 1;
    for (int i = 2; i < MAXN; i++) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
    ll n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        ll fuck = 1;
        REP(i, 0, n) {
            cin >> ar[i];
            ar[i]++;
            fuck = fuck * ar[i] % MOD;
        }
        ll ans = 0;
        REP(i, 0, n) {
            REP(j, i + 1, n) {
                ans += (min(ar[i], ar[j]) * fuck * inv[ar[i]] * inv[ar[j]]) % MOD;
            }
        }
        if (n == 1) ans = 1;
        cout << ans << endl;
    }
    return 0;
}