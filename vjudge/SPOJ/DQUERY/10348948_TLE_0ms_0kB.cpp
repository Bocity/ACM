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
int b[maxn], t[maxn], n, m, size, v[maxn], tot = 0;
struct chairtree {
    int l, r, size;
} a[maxn * 30];
int Build(int l, int r) {
    int root = ++tot;
    a[root].size = 0;
    if (l == r) return root;
    int m = (l + r) >> 1;
    a[root].l = Build(l, m);
    a[root].r = Build(m + 1, r);
    return root;
}
int Update(int root, int x) {
    int now = ++tot;
    int tmp = now;
    a[tot].size = a[root].size + 1;
    int l = 1, r = size;
    while (l < r) {
        int m = (l + r) >> 1;
        if (x <= m) {
            a[now].l = ++tot;
            a[now].r = a[root].r; //充分利用原来相同的结点
            root = a[root].l;
            now = tot;
            r = m;
        } else {
            a[now].l = a[root].l;
            a[now].r = ++tot;
            root = a[root].r;
            now = tot;
            l = m + 1;
        }
        a[now].size = a[root].size + 1;
    }
    return tmp;
}
int Ask(int lx, int rx) {
    if (a[lx].size == a[rx].size) return 0;
    if (a[lx].l == a[lx].r && a[rx].l == a[rx].r) {
        return (a[rx].size - a[lx].size > 0);
    }
    int ans = 0;
    ans += Ask(a[lx].l, a[rx].l);
    ans += Ask(a[lx].r, a[rx].r);
    return ans;
}
void Hash1() {
    sort(b + 1, b + 1 + n);
    size = unique(b + 1, b + 1 + n) - b - 1; //求不相同的数有几个
}
int Hash(int x) {
    return lower_bound(b + 1, b + 1 + size, x) - b; //找到x在排好序的序列中出现的位置，即离散化后的值
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]), b[i] = v[i];
    Hash1();
    t[0] = Build(1, size);
    for (int i = 1; i <= n; i++) //建n棵线段树
        t[i] = Update(t[i - 1], Hash(v[i]));
    scanf("%d", &m);
    while (m--) {
        int l, r, k;
        scanf("%d%d", &l, &r);
        printf("%d\n", Ask(t[l - 1], t[r]));
    }
    return 0;
}