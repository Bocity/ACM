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
const int N = 1000010;
int a[N];
set<ll> st;
int main() {
    int n, k, ccnt = 1, t;
    read(t);
    while (t--) {
        read(n), read(k);
        REP(i, 0, n) read(a[i]);
        ll sum = 0;
        st.clear();
        st.insert(0);
        bool flag = false;
        REP(i, 0, n) {
            sum += a[i];
            if (i & 1) {
                st.insert(a[i]);
            } else {
                auto pos = st.lower_bound(sum - k);
                if (pos != st.end() && *pos == sum - k) {
                    flag = true;
                    break;
                }
            }
        }
        st.clear();
        st.insert(0);
        REP(i, 1, n) {
            sum += a[i];
            if (i % 2 == 0) {
                st.insert(a[i]);
            } else {
                auto pos = st.lower_bound(sum - k);
                if (pos != st.end() && *pos == sum - k) {
                    flag = true;
                    break;
                }
            }
        }
        printf("Case #%d: ", ccnt++);
        puts(flag ? "Yes." : "No.");
    }
    return 0;
}