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
set<int> q;
template <class T> inline void print(T p) {
    if (!p) {
        puts("0");
        return;
    }
    while (p) stk[++tp] = p % 10, p /= 10;
    while (tp) putchar(stk[tp--] + '0');
    putchar('\n');
}
struct fl {
    int cost;
    int time;
    int ans;
} c[10000007];
bool cmpc(fl x, fl y) {
    if (x.cost == y.cost) return x.time > y.time;
    return x.cost > y.cost;
}
bool cmpt(fl x, fl y) {
    return x.time < y.time;
}
typedef long long ll;
typedef bitset<1005> Bitset;
const int maxn = 10005;
int n, k;
ll anss;
int C;
int main() {
    ios::sync_with_stdio(0);
    anss = 0;
    cin >> n >> k;
    REP(i, 0, n) {
        cin >> C;
        c[i].cost = C;
        c[i].time = i + 1;
        c[i].ans = 0;
    }
    REP(i, 0, n) {
        q.insert(k + i + 1);
    }
    sort(c, c + n, cmpc);
    REP(i, 0, n) {
        // cout << q.size() << endl;
        if (c[i].time > k) {
            // cout << c[i].time;
            if (q.find(c[i].time) != q.end()) {
                c[i].ans = c[i].time;
                // cout << c[i].time << endl;
                q.erase(c[i].time);
            } else {
                c[i].ans = *q.begin();
                // cout << c[i].time << endl;
                q.erase(c[i].ans);
            }

        } else {
            c[i].ans = *q.begin();
            q.erase(c[i].ans);
        }
        // for (auto j : q) {
        //     cout << j << " ";
        // }
        // cout << endl;
        // cout << c[i].ans << " ";
        // cout << endl;
        anss += (c[i].ans - c[i].time) * c[i].cost;
    }
    sort(c, c + n, cmpt);
    cout << anss << endl;
    REP(i, 0, n - 1) {
        cout << c[i].ans << " ";
    }
    cout << c[n - 1].ans << endl;
    return 0;
}