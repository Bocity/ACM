#include <bits/stdc++.h>
#define REP(i, x, n) for (long long i = (x); i < (n); i++)
#define PER(i, x, n) for (long long i = (n); i >= (x); i--)
#define endl "\n"
#define maxn 100000
#define N 50015
#define MOD 998244353
#define mems(a, x) memset(a, (x), sizeof a)
typedef long long ll;
using namespace std;
int n, m, q, t, k[N], a[N], b[N], maxk, ans[N];
bitset<50004> bs, aa, bb;
int main() {
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        bs.reset();
        aa.reset();
        bb.reset();
        cin >> n >> m >> q;
        maxk = 0;
        REP(i, 0, n) {
            cin >> a[i];
        }
        REP(i, 0, m) {
            cin >> b[i];
        }
        REP(i, 0, q) {
            cin >> k[i];
        }
        REP(i, 0, m) maxk = max(maxk, b[i]);
        REP(i, 0, n) aa.set(a[i]);
        REP(i, 0, m) bb.set(b[i]);
        PER(i, 0, maxk) {
            ans[i] = ((bs << i) & aa).count() & 1;
            if (bb[i]) {
                for (ll j = 0; j <= maxk; j += i) bs.flip(j);
            }
        }
        REP(i, 0, q) cout << ans[k[i]] << endl;
    }
    return 0;
}