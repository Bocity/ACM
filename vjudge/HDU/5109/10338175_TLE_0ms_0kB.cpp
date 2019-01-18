#include <bits/stdc++.h>
#define REP(i, x, n) for (long long i = (x); i < (n); ++i)
#define PER(i, x, n) for (long long i = (n) -1; i >= x; --i)
#define endl "\n"
#define DE puts("----------")
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
    PER(i, 0, s.size()) {
        ans += ans * 10 + s[i] - '0';
    }
    return ans;
}
bool dfs(string x, string y, string z) {
    ll p = calc(x + y + z);
    if (p % a == 0) {
        cout << p / a << endl;
        return true;
    }

    return false;
}
string num2(ll x) {
    stringstream ss;
    ss << x;
    return ss.str();
}
void ppstay() {
    if (calc(s) % a == 0) {
        cout << calc(s) / a << endl;
        return;
    }
    string x, z;
    ll st = 0;
    if (s[0] == '0') st = 1;
    REP(i, 1, 10000) {
        REP(j, 0, i) {
            ll po = (ll) pow(10, j);
            ll po2 = (ll) pow(10, i - j);
            REP(k, po, po * 10) {
                REP(l, po2, po2 * 10) {
                    x = num2(k);
                    z = num2(l);
                    if (dfs(x, s, z)) {
                        return;
                    }
                }
                string sss = "0", ssss = "0";
                REP(l, 0, i - j) {
                    sss += ssss;
                }
                if (dfs(x, s, sss)) {
                    return;
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    while (cin >> a >> s) {
        ppstay();
    }
    return 0;
}