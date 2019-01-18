#include <cstring>
#include <iostream>
#include <string.h>
using namespace std;
bool vis[100005] = {0};
int ans = 0;
int a[100005], n, t, sum;
bool dfs(int x, int summ) {
    if (vis[x] || summ > sum / 4) {
        return 0;
    }
    vis[x] = true;
    if (summ == sum / 4) {
        ans++;
        return 1;
    }
    for (int i = 1; i <= n; i++) {
        bool flag = dfs(i, summ + a[i]);
        if (flag) {
            // cout << i << " ";
            return 1;
        }
    }
    vis[x] = false;
    return 1;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        sum = 0;
        ans = 0;
        memset(vis, 0, sizeof(vis));
        memset(a, 0, sizeof(a));
        // cout << sum << ans;
        // for (int i = 1; i <= n; i++) cout << vis[i] << a[i];
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (sum % 4) {
            cout << "no\n";
            continue;
        }
        for (int i = 1; i <= n; i++) {
            bool oo = dfs(i, a[i]);
        }
        if (ans == 4)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
