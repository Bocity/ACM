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
char stk[1000];
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
int main() {
    ios::sync_with_stdio(0);
    while (cin >> s) {
        if (s.length() < 3) {
            cout << "NO" << endl;
            continue;
        }
        char a = s[0];
        int pos = 0;
        int len = 0, len2 = 0;
        int t = 0;
        while (pos < s.size()) {
            if (s[pos] == a) {
                len++;
                // cout << len << " " << pos << " " << len2 << endl;
                if (len != len2 && pos == s.size() - 1) {
                    t = 20;
                    break;
                }
                pos++;
            } else {
                if (len2 != 0 && len != len2) {
                    break;
                    t = 19;
                }
                len2 = len;
                a = s[pos];
                t++;
                len = 0;
            }
        }
        if (t == 2) {
            cout << "YES" << endl;
            continue;
        } else {
            cout << "NO" << endl;
            continue;
        }
    }

    return 0;
}