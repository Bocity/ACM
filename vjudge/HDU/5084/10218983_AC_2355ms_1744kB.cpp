#include <bits/stdc++.h>
#define REP(i, x, n) for (long long i = (x); i < (n); i++)
#define endl "\n"
#define maxn 100000
#define N 1500015
#define MOD 998244353
#define mems(a, x) memset(a, (x), sizeof a)
typedef long long ll;
using namespace std;
ll n;
ll M[maxn], l, r, ANS, anss, m;
int main() {
    ios::sync_with_stdio(0);
    while (cin >> n) {
        // memset(M, 0, sizeof M);
        anss = 0;
        REP(i, 0, 2 * n - 1) {
            cin >> M[i];
        }
        cin >> m;
        REP(i, 0, m) {
            cin >> l >> r;
            if (i >= 1) {
                int L, R;
                l = (l + ANS) % n;
                r = (r + ANS) % n;
                L = n - 1 - l;
                R = n - 1 + r;
                ANS = 0;
                REP(i, 0, n) {
                    ANS += M[L] * M[R];
                    L++;
                    R--;
                }
            } else {
                int L, R;
                L = n - 1 - l;
                R = n - 1 + r;
                ANS = 0;
                REP(i, 0, n) {
                    ANS += M[L] * M[R];
                    L++;
                    R--;
                }
            }
            anss += ANS;
        }
        cout << anss << endl;
    }
    return 0;
}