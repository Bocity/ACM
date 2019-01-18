#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n) -1; i >= x; --i)
#define endl "\n"
#define DE puts("----------")
#define CASE(i, ans) cout << "Case #" << (i) << ": " << (ans) << "\n"
#define lowbit(x) ((x) & (-(x)))
#pragma comment(linker, "/stack:1024000000,1024000000")
#define sqr(x) ((x) * (x))
#define eps 1e-9
#define PI acos(-1.0)
#define MOD 1000000007
#define testin freopen("test.in", "r", stdin)
#define testout freopen("test.out", "w", stdout)
using namespace std;
typedef long long ll;
typedef bitset<1005> Bitset;
const int maxn = 10005;
int n, a, b;
int h[200], H[200];
struct qq {
    vector<char> qw;
};
void printt(qq x) {
    cout << x.qw.size() << endl;
    REP(i, 0, x.qw.size() - 1) {
        cout << (int) x.qw[i] << " ";
    }
    cout << (int) x.qw[x.qw.size() - 1] << endl;
}
bool check(qq x) {
    REP(i, 1, n + 1) {
        H[i] = h[i];
    }
    int xl = x.qw.size();
    REP(i, 0, xl) {
        H[x.qw[i]] -= a;
        H[x.qw[i] + 1] -= b;

        H[x.qw[i] - 1] -= b;
    }
    REP(i, 1, n + 1) {
        if (H[i] >= 0) return false;
    }
    return true;
}
bool check2(qq x, int y) {
    REP(i, 1, n + 1) {
        H[i] = h[i];
    }
    int xl = x.qw.size();
    REP(i, 0, xl) {
        H[x.qw[i]] -= a;
        H[x.qw[i] + 1] -= b;

        H[x.qw[i] - 1] -= b;
    }
    if (H[y] < 0 && H[y + 1] < 0 || H[y] < 0 && H[y - 1] < 0) return true;
    return false;
}
void bfs() {
    queue<qq> q;
    qq q1;
    REP(i, 2, n) {
        q1.qw.clear();
        q1.qw.push_back(i);
        q.push(q1);
    }
    qq pp;
    qq tt;
    while (!q.empty()) {
        pp = q.front();
        if (check(pp)) {
            printt(pp);
            return;
        }
        q.pop();
        for (int i = 2; i < n; i++) {
            // if (check2(pp, i)) continue;
            if (pp.qw[pp.qw.size() - 1] > i) continue;
            tt = pp;
            tt.qw.push_back(i);
            q.push(tt);
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin >> n >> a >> b;
    REP(i, 1, n + 1) {
        cin >> h[i];
    }
    bfs();
    return 0;
}