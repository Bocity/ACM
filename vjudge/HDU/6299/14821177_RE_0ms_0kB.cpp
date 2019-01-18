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
} s[100005];
node anss;
int ans = 0;
bool cmp(node &x, node &y) { // x.l > y.l   x.r < y.r   x.l  < y.l  x.r > y.r
    if (x.r == y.r) return x.l > y.l;
    if (x.l == y.l) return x.r < y.r;
    return (x.l > y.l || x.r < y.r);
}
stack<char> q;
string p = "";
void fuck(node &x) {
    int t = (int) x.s.size();
    while (!q.empty()) q.pop();
    p = "";
    REP(i, 0, t) {
        if (x.s[i] == ')') {
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
    x.r = (int) q.size();
    x.l = 0;
    while (!q.empty() && q.top() == '(') {
        q.pop();
        x.l++;
        x.r--;
    }
    REP(i, 0, x.r) {
        p += ')';
    }
    REP(i, 0, x.l) {
        p += '(';
    }
    x.s = p;
}
int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ans = 0;
        REP(i, 0, n) {
            cin >> s[i].s;
        }
        REP(i, 0, n) {
            fuck(s[i]);
        }
        sort(s, s + n, cmp);
        anss.s = "";
        REP(i, 0, n) {
            anss.s += s[i].s;
        }
        fuck(anss);
        cout << ans * 2 << endl;
    }

    return 0;
}