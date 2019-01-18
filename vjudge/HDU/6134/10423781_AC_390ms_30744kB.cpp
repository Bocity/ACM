#include <algorithm>
#include <bits/stdc++.h>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (long long i = (n) -1; i >= x; --i)
#define endl "\n"
#define DE(x) cout << "--------\n" << (x) << "----------\n"
#define CASE(i, ans) cout << "Case #" << (i) << ": " << (ans) << "\n"
#define lowbit(x) ((x) & (-(x)))
#define sqr(x) ((x) * (x))
#define eps 1e-9
#define PI acos(-1.0)
#define testin freopen("test.in", "r", stdin)
#define testout freopen("test.out", "w", stdout)
using namespace std;
typedef long long ll;
typedef bitset<1005> Bitset;
const int maxn = 1000150;
template <class T> void read(T &num) {
    char CH;
    bool F = false;
    num = 0;
    for (CH = getchar(); CH < '0' || CH > '9'; F = CH == '-', CH = getchar())
        ;
    for (num = 0; CH >= '0' && CH <= '9'; num = num * 10 + CH - '0', CH = getchar())
        ;
    F && (num = -num);
}
char stk[600];
int tp = 0;
template <class T> inline void print(T p) {
    if (!p) {
        puts("0");
        return;
    }
    while (p) stk[++tp] = p % 10, p /= 10;
    while (tp) putchar(stk[tp--] + '0');
    putchar('\n');
}
ll p[1000015], cnt = 0;
bool vis[1000015] = {true, true};
int u[1000015];
void Init() {
    memset(vis, 0, sizeof(vis));
    u[1] = 1;
    cnt = 0;
    for (int i = 2; i < 1000005; i++) {
        if (!vis[i]) {
            p[cnt++] = i;
            u[i] = -1;
        }
        for (int j = 0; j < cnt && i * p[j] < 1000005; j++) {
            vis[i * p[j]] = 1;
            if (i % p[j]) {
                u[i * p[j]] = -u[i];
            } else {
                u[i * p[j]] = 0;
                break;
            }
        }
    }
    // sum[0] = 0;
    // for (int i = 1; i < N; i++) sum[i] = sum[i - 1] + mu[i];
}
const long long MOD = 1000000007;
ll g[1000015], ans[1000015], test[1000], gg[1000015];
ll n;
int main() {
    Init();
    ios::sync_with_stdio(0);
    // REP(i, 1, 100) {
    //     REP(j, 1, i + 1) {
    //         test[i] += (i + j - 1) / j;
    //     }
    // }
    // REP(i, 1, 100) cout << test[i] << " ";
    // cout << endl;
    for (int j = 1; j <= 1000000; j++) {
        gg[j]++;
        for (int i = j; i <= 1000000; i += j) {
            gg[i + 1]++;
        }
    }
    g[1] = 1;
    REP(i, 2, 1000001) {
        g[i] += g[i - 1] + gg[i];
    }
    // REP(i, 1, 100) cout << g[i] << " ";
    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) {
            ans[j] = (ans[j] + (u[j / i] * g[i])) % MOD;
        }
    }
    REP(i, 2, 1000001) {
        ans[i] = (ans[i - 1] + ans[i]) % MOD;
    }
    while (cin >> n) {
        cout << ans[n] << endl;
    }
    return 0;
}