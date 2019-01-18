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
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
vector<long long> prime;
#define N 1000000 // range to screen
bool vis[N] = {true, true};
void screen() {
    for (long long i = 2; i < N; i++) {
        if (!vis[i]) prime.push_back(i);
        for (int j = 0; j < prime.size() && i * prime[j] < N; j++) {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    screen();
    ll t, l, r, k, temp, cnt;
    cin >> t;
    while (t--) {
        cin >> l >> r >> k;
        ll ans = 0;
        for (ll i = l; i <= r; i++) {
            temp = 1;
            ll ii = i;
            for (auto j : prime) {
                if (j > ii) break;
                cnt = 0;
                while (ii % j == 0) {
                    cnt++;
                    ii /= j;
                }
                temp *= cnt * k + 1;
            }
            if (ii != 1) temp *= k + 1;
            ans = (ans + temp) % MOD;
        }
        cout << ans << endl;
    }
}