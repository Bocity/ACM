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
int main() {
    ios::sync_with_stdio(false);
    int t;
    ll n;
    screen();
    while (cin >> n) {
        int ans = 0, fuck;
        bool flag = true;
        REP(ii, 0, tot) {
            int i = prime[ii];
            if (i > n) break;
            while (n % i == 0) {
                if (flag) {
                    fuck = i;
                    flag = false;
                }
                n /= i;
                ans++;
            }
        }
        if (n != 1) ans++;
        if (ans == 1)
            cout << 1 << endl;
        else if (ans == 2)
            cout << fuck << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}