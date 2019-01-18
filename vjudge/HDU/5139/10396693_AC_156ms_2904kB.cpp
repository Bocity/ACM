#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#define REP(i, x, n) for (long long i = (x); i < (n); ++i)
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
#define MOD 2
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
// ll g[10000008];
// void biao() {
//     g[1] = 1;
//     ll temp = 1;
//     REP(i, 2, 10000001) {
//         temp = temp * i % 1000000007;
//         g[i] = g[i - 1] * temp % 1000000007;
//     }
// }
int n;
struct ss {
    int id, q, ans;
};
ss Q[100005];
int main() {
    ios::sync_with_stdio(0);
    // testin;
    // testout;
    // biao();
    // cout << "{";
    // REP(i, 1, 10000001) {
    //     if (i % 5000 == 0) {
    //         cout << g[i] << ",";
    //     }
    // }
    // cout << "}";
    // while (~scanf("%d", &n)) {
    //     int temp = n / 5000;
    //     ll F = 1;
    //     ll G = 1;
    //     temp--;
    //     if (temp < 0) {
    //         REP(i, 2, n + 1) {
    //             F = F * i % 1000000007;
    //             G = G * F % 1000000007;
    //         }
    //         print(G);
    //     } else {
    //         F = f[temp];
    //         G = gg[temp];
    //         REP(i, (temp + 1) * 5000 + 1, n + 1) {
    //             F = F * i % 1000000007;
    //             G = G * F % 1000000007;
    //         }
    //         print(G);
    //     }
    // }

    int res = 0;
    while (cin >> n) {
        if (n == 0) break;
        Q[res].q = n;
        Q[res].id = res;
        res++;
    }
    sort(Q, Q + res, [](ss x, ss y) { return x.q < y.q; });
    int pos = 0;
    ll F = 1;
    ll G = 1;
    if (Q[pos].q == 1) {
        Q[pos].ans = 1;
        pos++;
    }
    REP(i, 2, 10000001) {
        F = F * i % 1000000007;
        G = G * F % 1000000007;
        if (pos >= res) break;
        while (Q[pos].q == i) {
            Q[pos].ans = G;
            pos++;
        }
    }
    sort(Q, Q + res, [](ss x, ss y) { return x.id < y.id; });
    REP(i, 0, res) {
        cout << Q[i].ans << endl;
    }
    return 0;
}