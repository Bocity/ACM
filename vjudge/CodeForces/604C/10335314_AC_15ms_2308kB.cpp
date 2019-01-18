#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n) -1; i >= x; --i)
#define endl "\n"
#define DE puts("----------")
#define CASE(i, ans) cout << "Case #" << (i) << ": " << (ans) << "\n"
#define lowbit(x) ((x) & (-(x)))
#define sqr(x) ((x) * (x))
#define eps 1e-9
#define PI acos(-1.0)
#define MOD 1000000007
#define testin freopen("test.in", "r", stdin)
#define testout freopen("test.out", "w", stdout)
using namespace std;
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

typedef long long ll;
typedef bitset<1005> Bitset;
const int maxn = 10005;
string s;
void stay(int n) {
    cin >> s;
    char temp = 'x';
    long long ans = 0, anss = 0;
    REP(i, 0, n) {
        if (s[i] != temp) {
            temp = s[i];
            ans++;
        }
        if (i > 0 && s[i] == s[i - 1]) {
            anss++;
        }
    }
    if (anss > 1)
        cout << ans + 2 << endl;
    else
        cout << ans + anss << endl;
}
int n;
int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    stay(n);
    return 0;
}