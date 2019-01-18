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
int gg[1000005];
int f[1000005];
void biao() {
    ll temp2 = 1;
    ll temp = 1;
    int pos = 0;
    REP(i, 2, 10000001) {
        temp = temp * i % 1000000007;
        temp2 = temp2 * temp % 1000000007;
        if (i % 10 == 0) {
            f[pos] = temp;
            gg[pos] = temp2;
            pos++;
        }
    }
}
int n;
int main() {
    ios::sync_with_stdio(0);
    biao();
    while (~scanf("%d", &n)) {
        int temp = n / 10;
        ll F = 1;
        ll G = 1;
        temp--;
        if (temp < 0) {
            REP(i, 2, n + 1) {
                F = F * i % 1000000007;
                G = G * F % 1000000007;
            }
            print(G);
        } else {
            F = f[temp];
            G = gg[temp];
            REP(i, (temp + 1) * 10 + 1, n + 1) {
                F = F * i % 1000000007;
                G = G * F % 1000000007;
            }
            print(G);
        }
    }
    return 0;
}