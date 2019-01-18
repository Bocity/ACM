#include <bits/stdc++.h>
#define REP(i, x, n) for (long long i = (x); i < (n); ++i)
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
#define E 1e-10
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

double f(double x, double num) // 函数
{
    return x * x * x - num;
}

double _f(double x) // 导函数
{
    return 3 * x * x;
}

double getCubeRoot(double input) {
    double x0;
    double r = 1;
    do {
        x0 = r;
        r = x0 - f(x0, input) / _f(x0);
    } while (f(r, input) > E || f(r, input) < -E);

    return r;
}
int n;
string s;
vector<int> q;
bool check() {
    REP(i, 0, s.size()) {
        if (s[i] != s[s.size() - 1 - i]) return false;
    }
    return true;
}
int main() {
    cin.tie(0);
    while (cin >> n) {
        q.clear();
        int ans = 0;
        cin >> s;
        REP(i, 0, s.size()) {
            if (s[i] == '?') {
                ans++;
                q.push_back(i);
                s[i] = 'a';
            }
        }
        if (!ans) {
            bool flag = false;
            REP(i, 0, s.size()) {
                if (s[i] != s[s.size() - i - 1]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                cout << "QwQ" << endl;
            } else {
                cout << s << endl;
            }
        } else {
            if (ans == 1 && (s.size() % 2) && q[0] == ((s.size() - 1) / 2) && check()) {
                cout << "QwQ" << endl;
                continue;
            }
            if (check()) {
                s[q[q.size() - 1]]++;
            }
            cout << s << endl;
        }
    }
    return 0;
}