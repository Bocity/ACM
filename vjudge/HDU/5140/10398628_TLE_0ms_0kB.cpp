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
#define LSON l, m, rt << 1
#define RSON m + 1, r, rt << 1 | 1
#define lson rt << 1
#define rson rt << 1 | 1
using namespace std;
typedef long long ll;
typedef bitset<1005> Bitset;
const int maxn = 1000150;
const long long MAXN = 200005;
long long sum[MAXN << 2], tag[MAXN << 2], Maxl[MAXN << 2], Minl[MAXN << 2], Maxa[MAXN << 2], Mina[MAXN << 2];
struct ss {
    int s, l, a;
} staff;
ll LL, HL, LA, HA;
void Maintain(long long rt) { //更新答案
    sum[rt] = sum[lson] + sum[rson];
    Maxa[rt] = max(Maxa[lson], Maxa[rson]);
    Maxl[rt] = max(Maxl[lson], Maxl[rson]);
    Mina[rt] = (Mina[lson] < Mina[rson]) ? Mina[lson] : Mina[rson];
    Minl[rt] = (Minl[lson] < Minl[rson]) ? Minl[lson] : Minl[rson];
    return;
}
/****************************************************************/
void update(long long L /*需要更新的点*/, ss c, long long l, long long r, long long rt /*=1*/) { //单点
    if (L == l && l == r) {
        sum[rt] = c.s;
        Maxl[rt] = c.l;
        Maxa[rt] = c.a;
        Minl[rt] = c.l;
        Mina[rt] = c.a;
        return;
    }
    long long m = (l + r) >> 1;
    if (L <= m)
        update(L, c, LSON);
    else
        update(L, c, RSON);
    Maintain(rt);
    return;
}
long long query2(long long L, long long R, long long l, long long r, long long rt /*=1*/) {
    if (LL > Maxl[rt] || LA > Maxa[rt] || HL < Minl[rt] || HA < Mina[rt]) return 0;
    if (L <= l && r <= R && LL <= Minl[rt] && HL >= Maxl[rt] && LA <= Mina[rt] && HA >= Maxa[rt]) {
        return sum[rt];
    }
    long long m = (l + r) >> 1;
    long long ret = 0;
    if (L <= m) ret += query2(L, R, LSON);
    if (m < R) ret += query2(L, R, RSON);
    return ret;
}
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

int S, L, A, m;
ll k = 0;
void stay(int n) {
    k = 0;
    REP(i, 1, n + 1) {
        cin >> S >> L >> A;
        staff.s = S;
        staff.l = L;
        staff.a = A;
        update(i, staff, 1, n, 1);
    }
    cin >> m;

    REP(i, 0, m) {
        cin >> LL >> HL >> LA >> HA;
        LL += k;
        HL -= k;
        LA += k;
        HA -= k;
        if (LL > HL) swap(LL, HL);
        if (LA > HA) swap(LA, HA);
        ll ans = query2(1, n, 1, n, 1);
        k = ans;
        cout << ans << endl;
    }
}
int n;
int main() {
    ios::sync_with_stdio(0);
    while (cin >> n) {
        stay(n);
    }
    return 0;
}