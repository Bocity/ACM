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
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define PI acos(-1.0)
using namespace std;
const int MOD = 1e9 + 7;
const int N = 100500;
const int INF = 0x3f3f3f3f;
int mem[N];
int main() {
    ios::sync_with_stdio(false);
    ll n, t;
    mem[1] = 1;
    for (int i = 2; i < N; i++) {
        mem[i] = (ll) mem[i - 1] * i % MOD;
    }
    cin >> t;
    while (t--) {
        cin >> n;
        if (n < 4) {
            cout << n << endl;
            continue;
        }
        ll temp = 2 * n + 2;
        ll x = sqrt(temp * 1.0) - 3;
        while ((x + 2) * (x - 1) <= temp) {
            x++;
        }
        x--;
        ll gap = n - (x + 2) * (x - 1) / 2;
        ll ans = mem[x - gap];
        // cout << gap << " " << ans << " " << x << endl;
        if (gap < 0) {
            ans = 1;
            for (ll i = 3; i <= x - 1; i++) {
                ans = ans * i % MOD;
            }
            ans = ans * (x + 1) % MOD;
            cout << ans << endl;
            continue;
        }
        for (ll i = x - gap + 1; i <= x; i++) {
            ans = ans * (i + 1) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}