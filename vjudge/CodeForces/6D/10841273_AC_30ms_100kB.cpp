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
const int maxn = 10005;
int n, a, b;
int h[200], H[200];
struct qq {
    char qw[11];
    char Max;
};
void printt(qq x) {
    int ans = 0;
    REP(i, 0, 11) {
        ans += x.qw[i];
    }
    cout << ans << endl;
    vector<int> ass;
    REP(i, 0, 11) {
        REP(j, 0, x.qw[i]) ass.push_back(i);
    }
    REP(i, 0, ass.size() - 1) {
        cout << (int) ass[i] << " ";
    }
    cout << (int) ass[ass.size() - 1] << endl;
}
inline bool check(qq x) {
    REP(i, 1, n + 1) {
        H[i] = h[i];
    }
    REP(i, 2, 11) {
        H[i] -= a * x.qw[i];
        H[i + 1] -= x.qw[i] * b;
        H[i - 1] -= x.qw[i] * b;
    }
    REP(i, 1, n + 1) {
        if (H[i] >= 0) return false;
    }
    cout << endl;
    return true;
}
void bfs() {
    queue<qq> q;
    qq q1;
    memset(q1.qw, 0, sizeof q1.qw);
    q1.qw[2]+=h[1]/b + 1;
    q1.Max = 2;
    if (check(q1)) {
            printt(q1);
            return;
    }
    if (H[n]>=0){
        q1.qw[n-1]+=H[n]/b + 1;
    }
    if (check(q1)) {
            printt(q1);
            return;
    }
    REP(i, 2, n) {
        if (H[i]<0&&(i==2||i==n-1)) continue;
        q1.qw[i]++;
        q1.Max = i;
        q.push(q1);
        q1.qw[i]--;
    }
    qq pp;
    qq tt;
    memset(pp.qw, 0, sizeof pp.qw);
    memset(tt.qw, 0, sizeof tt.qw);
       //  cout << H[2]<<endl;
    while (!q.empty()) {
        pp = q.front();
        if (check(pp)) {
            printt(pp);
            return;
        }
        q.pop();
        for (int i = n - 1; i >= 2; i--) {
            if (H[i] < 0 && H[i - 1] < 0 && H[i + 1] < 0) continue;
            if (H[i] < 0 && H[i - 1] < 0 && i + 1 != n) continue;
            if (H[i] < 0 && i - 1 != 1 && H[i + 1] < 0) continue;
            if (pp.Max > i) break;
            tt = pp;
            tt.qw[i]++;
            tt.Max = max(i, (int) tt.Max);
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