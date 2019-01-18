#include <bits/stdc++.h>
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
const int maxn = 100015;
const int N = 100015;
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
ll a, b;
string s;
ll calc(string s) {
    ll ans = 0;
    REP(i, 0, s.size()) {
        ans = ans * 10 + s[i] - '0';
    }
    return ans;
}
string num2(ll x) {
    stringstream ss;
    ss << x;
    return ss.str();
}
void ppstay() {
    if (calc(s) % a == 0 && s[0] != '0') {
        print(calc(s) / a);
        return;
    }
    ll base = 1;
    ll S = calc(s);
    ll t;
    ll b = -1;
    REP(i, 0, s.size()) {
        base *= 10;
    }
    for (int i = 1; i <= 10000; i *= 10) {
        for (int j = (s[0] == '0'); j < a; j++) {
            t = ((ll)(j) *base + S) * i;
            int mod = (a - t % a) % a;
            if (mod < i) {
                t += mod;
                if (b < 0 || t < b) b = t;
            }
        }
    }
    print(b / a);
}
int main() {
    ios::sync_with_stdio(0);
    while (cin >> a >> s) {
        ppstay();
    }
    return 0;
}