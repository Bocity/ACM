#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = x; i < n; ++i)
using namespace std;
const int N = 1005;

bitset<1005> sw[N], ans;
int n, m, k, p,x;
int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    cin >> k;
    REP(i, 0, k) {
        cin >> x;
        ans.set(x);
    }
   // cout << ans << endl;
    //cout << ans.count() << endl;
    REP(i, 0, n) {
        cin >> k;
        REP(j, 0, k) {
            cin >> x;
            sw[i].set(x);
        }
    }
    int anss = 0;
    for (int i = 0; i <= n * m; ++i) {
        if (ans.count() == 0) {
            cout << anss << endl;
            return 0;
        }
        ans = ans ^ sw[i % n];
        anss++;
    }
    cout << -1 << endl;
    return 0;
}
