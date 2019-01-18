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
const ll MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;
int ar[MAXN], br[MAXN];
bool vis[MAXN];
map<int, ll> cnt1, cnt2;
void fuck(auto a, auto n, auto &st) {
    mems(vis, false);
    REP(i, 0, n) {
        if (!vis[i]) {
            vis[i] = true;
            int p = i, sz = 1;
            while (!vis[a[p]]) {
                p = a[p];
                vis[p] = true;
                sz++;
            }
            st[sz]++;
        }
    }
}
long long pow(long long a, long long b, long long p) { // return a^b %p
    long long t = 1;
    for (a %= p; b; b >>= 1LL, a = a * a % p)
        if (b & 1LL) t = t * a % p;
    return t;
}
int main() {
    ios::sync_with_stdio(false);
    int cas = 1, n, m;
    while (cin >> n >> m) {
        REP(i, 0, n) cin >> ar[i];
        REP(i, 0, m) cin >> br[i];
        cnt1.clear(), cnt2.clear();
        fuck(ar, n, cnt1), fuck(br, m, cnt2);
        ll ans = 1;
        for (auto i : cnt1) {
            ll temp = 0;
            for (auto j : cnt2) {
                if (i.first % j.first == 0) {
                    temp = (temp + j.first * j.second) % MOD;
                }
            }
            ans = (ans * pow(temp, i.second, MOD)) % MOD;
        }
        cout << "Case #" << cas++ << ": " << ans << endl;
    }
    return 0;
}