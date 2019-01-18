#include <bits/stdc++.h>
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
namespace fastIO {
#define BUF_SIZE 100000
// fread -> read
bool IOerror = 0;
inline char nc() {
    static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
    if (p1 == pend) {
        p1 = buf;
        pend = buf + fread(buf, 1, BUF_SIZE, stdin);
        if (pend == p1) {
            IOerror = 1;
            return -1;
        }
    }
    return *p1++;
}
inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline bool read(auto &x) {
    char ch;
    bool ne = false;
    while (blank(ch = nc()))
        ;
    if (IOerror) return false;
    if (ch == '-') ne = true, ch = nc();
    for (x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0')
        ;
    if (ne) x = -x;
    return true;
}
#undef BUF_SIZE
};
using namespace fastIO;
const int N = 100000;
struct piii {
    int first, second, third;
    bool operator<(const piii &o) {
        if (first != o.first) return first > o.first;
        if (second != o.second) return second < o.second;
        return third < o.third;
    }
} a[N];
int main() {
    int n;
    while (read(n)) {
        int x, y;
        REP(i, 0, n) read(x), read(y), a[i].first = x - y, a[i].second = y, a[i].third = i;
        sort(a, a + n);
        REP(i, 0, n) printf("%d%c", a[i].third, " \n"[i == n - 1]);
    }
    return 0;
}