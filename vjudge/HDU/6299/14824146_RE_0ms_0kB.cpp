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
using namespace std;
typedef long long ll;
ll n, m, k;
const long long mod = 1000000007;
struct node {
    string s;
    int l;
    int r;
} S[100005];
node anss;
int ans = 0;
bool cmp(node x, node y) { // x.l > y.l   x.r < y.r   x.l  < y.l  x.r > y.r
    // if (x.r == y.r) return x.l > y.l;
    // if (x.l == y.l) return x.r < y.r;
    // return (x.l > y.l || x.r < y.r);
    int xx = min(x.l, y.r);
    int yy = min(x.r, y.l);
    return xx > yy || xx == yy && x.l > y.r;
}
stack<char> q;
inline void fuck(string s,int pos) {
    int t = (int) s.size();
    while (!q.empty()) q.pop();
    REP(i, 0, t) {
        if (s[i] == ')') {
            if (!q.empty() && q.top() == '(') {
                q.pop();
                ans++;
            } else {
                q.push(')');
            }
        } else {
            q.push('(');
        }
    }
    S[pos].r = (int) q.size();
    S[pos].l = 0;
    while (!q.empty() && q.top() == '(') {
        q.pop();
        S[pos].l++;
        S[pos].r--;
    }
    string p = "";
    REP(i, 0, S[pos].r) {
        p += ')';
    }
    REP(i, 0, S[pos].l) {
        p += '(';
    }
    S[pos].s = p;
}
int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ans = 0;
        string ss;
        REP(i, 0, n) {
            cin >> ss;
            S[i].s = ss;
        }
        REP(i, 0, n) {
            fuck(S[i].s, i);
        }
        sort(S, S + n, cmp);
        string sss = S[0].s;
        REP(i, 1, n) {
            sss += S[i].s;
        }
        fuck(sss, 0);
        cout << ans * 2 << endl;
    }

    return 0;
}