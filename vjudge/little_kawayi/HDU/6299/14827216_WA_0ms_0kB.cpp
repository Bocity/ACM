#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n) -1; i >= x; --i)
using namespace std;
typedef long long ll;
int n, m, k;
const long long mod = 1000000007;
struct node {
    string s;
    int l;
    int r;
} S[100005];
int ans = 0;
bool cmp(const node &x, const node &y) {
    int xx = min(x.l, y.r);
    int yy = min(x.r, y.l);
    return xx > yy || xx == yy && x.l > y.r;
}
char stk[100050];
inline void fuck(string &s, int pos) {
    int t = int(s.size());
    int top = 0;
    REP(i, 0, t) {
        if (s[i] == ')') {
            if (top > 0 && stk[top - 1] == '(') {
                top--;
                S[pos].l--;
            } else {
                S[pos].r++;
                stk[top] = ')';
                top++;
            }
        } else {
            S[pos].l++;
            stk[top] = '(';
            top++;
        }
        // cout << top << ' ' << S[pos].l << ' ' << S[pos].r << endl;
    }
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
        // sort(S, S + n, cmp);
        ans = 0;
        cout << ans * 2 << endl;
    }

    return 0;
}