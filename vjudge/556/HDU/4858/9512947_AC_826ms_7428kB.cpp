#include <bits/stdc++.h>
using namespace std;
vector<int> ve[100050];
int cnt[100050];
int main() {
    ios::sync_with_stdio(false);
    int t, n, m, q, cmd, u, v;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) ve[i].clear();
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            ve[u].push_back(v);
            ve[v].push_back(u);
        }
        cin >> q;
        while (q--) {
            cin >> cmd;
            if (cmd) {
                cin >> u;
                long long ans = 0;
                for (auto i : ve[u]) {
                    ans += cnt[i];
                }
                cout << ans << endl;
            } else {
                cin >> u >> v;
                cnt[u] += v;
            }
        }
    }
}