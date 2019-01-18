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
bool cmp(node x, node y) {
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
            } else {
                stk[top] = ')';
                top++;
            }
        } else {
            stk[top] = '(';
            top++;
        }
    }
    // assert(top > 0);
    if (top >= 0) {
        S[pos].r = top;
        S[pos].l = 0;
    } else {
        S[pos].r = 0;
        S[pos].l = 0;
    }
    while (top >= 0 && stk[top - 1] == '(') {
        top--;
        S[pos].l++;
        S[pos].r--;
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
        sort(S, S + n, cmp);
        ans = 0;
        // int top = 0;
        // REP(i, 0, n) {
        //     int sz = S[i].s.size();
        //     REP(j, 0, sz) {
        //         if (S[i].s[j] == ')') {
        //             if (top != 0 && stk[top - 1] == '(') {
        //                 top--;
        //                 ans++;
        //             } else {
        //                 stk[top] = ')';
        //                 top++;
        //             }
        //         } else {
        //             stk[top] = '(';
        //             top++;
        //         }
        //     }
        // }
        cout << ans * 2 << endl;
    }

    return 0;
}