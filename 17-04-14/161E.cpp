#include <cstdio>
#include <cstring>
#include <iostream>
#include <string.h>
using namespace std;
bool vis[100] = {0};
int ans = 0;
int a[100], n, t, sum;
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
        if (vis[i]) continue;
        if (ans == 4 || (!vis[i] && dfs(i, summ + a[i]))) {
            // cout << i << " ";
            return 1;
        }
    }
    vis[x] = false;
    return 0;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        sum = 0;
        ans = 0;
        memset(vis, 0, sizeof(vis));
        int maxx = -1;
        // cout << sum << ans;
        // for (int i = 1; i <= n; i++) cout << vis[i] << a[i];
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
            maxx = max(a[i], maxx);
        }
        if (sum % 4) {
            cout << "no\n";
            continue;
        }
        if (maxx > sum / 4) {
            cout << "no\n";
            continue;
        }
        bool oo = true;
        for (int i = 1; i <= n; i++) {
            oo = true;
            if (ans == 4) break;
            if (vis[i]) continue;
            if (ans != 4 && !vis[i]) oo = dfs(i, a[i]);
            if (!oo) {
                ans = 0;
                break;
            }
        }
        if (ans == 4)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
