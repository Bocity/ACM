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
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef bitset<1005> Bitset;
const int maxn = 1000150;
const int N = 1000150;
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
int a[10000], anss, x, maxx;
int n;
void stay() {
    memset(a, 0, sizeof a);
    maxx = 0;
    cin >> n;
    anss = 0;
    REP(i, 0, n) {
        cin >> x;
        a[x]++;
        if (a[x] > maxx) {
            maxx = a[x];
            anss = x;
        } else if (a[x] == maxx) {
            anss = min(x, anss);
        }
    }
    cout << anss << endl;
}
int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        stay();
    }
    return 0;
}