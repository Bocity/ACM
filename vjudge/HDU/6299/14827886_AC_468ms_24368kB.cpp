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
};
node *s;
node anss;
int ans = 0;
bool cmp(node y, node x) {
    if (x.l >= x.r && y.l < y.r) return false;
    if (x.l < x.r && y.l >= y.r) return true;
    if (x.l >= x.r && y.l >= y.r) return x.r > y.r;
    return x.l < y.l;
}
stack<char> q;
void fuck(node &x) {
    int t = (int) x.s.size();
    while (!q.empty()) q.pop();
    string p = "";
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
    // cout << unsigned(-1);
    while (t--) {
        cin >> n;
        ans = 0;
        s = new node[n + 1];
        REP(i, 0, n) {
            cin >> s[i].s;
        }
        REP(i, 0, n) {
            fuck(s[i]);
        }
        stable_sort(s, s + n, cmp);
        while (!q.empty()) q.pop();
        REP(i, 0, n) {
            int sz = s[i].s.size();
            REP(j, 0, sz) {
                if (s[i].s[j] == ')') {
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
        }
        cout << ans * 2 << endl;
    }
    return 0;
}