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
    ios::sync_with_stdio(false);
    int t;
    int n;
    screen();
    while (cin >> n) {
        int ans = 0;
        REP(i, 0, tot) {
            if (prime[i] > n) break;
            REP(j, i, tot) {
                if (prime[i] + prime[j] > n) break;
                int temp = n - prime[i] - prime[j];
                if (temp >= prime[j] && !vis[temp]) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}