#include <bits/stdc++.h>
using namespace std;
int n, m;
int x[] = {-1, 1, 0, 0};
int y[] = {0, 0, -1, 1};
char mp[50][50];
bool vis[50][50];
bool cango(int x, int y) {
    return (x < n && x > -1 && y < m && y > -1);
}
int dfs(int posx, int posy) {
    vis[posx][posy] = true;
    int cnt = 0;
    for (int k = 0; k < 4; k++) {
        int xx = posx + x[k];
        int yy = posy + y[k];
        if (!cango(xx, yy)) cnt++;
        if (cango(xx, yy) && (mp[xx][yy] == 'E' || mp[xx][yy] == 'D')) {
            cnt++;
        }
        if (cango(xx, yy) && !vis[xx][yy] && mp[xx][yy] == '.') {
            cnt += dfs(xx, yy);
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(false);
    int t, ans;
    cin >> t;
    for (int cas = 1; cas <= t; cas++) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mp[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mp[i][j] == 'E') {
                    int cnt = 0;
                    for (int k = 0; k < 4; k++) {
                        int xx = i + x[k];
                        int yy = j + y[k];
                        if (cango(xx, yy) && mp[xx][yy] == '.') {
                            cnt++;
                        }
                    }
                    // cout << cnt << endl;
                    if (cnt < 1) {
                        mp[i][j] = '.';
                    }
                }
            }
        }
        int ans = 0;
        memset(vis, false, sizeof vis);
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << mp[i][j];
        //     }
        //     cout << endl;
        // }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && mp[i][j] == '.') ans += dfs(i, j);
            }
        }
        cout << "Case " << cas << ": " << ans << endl;
    }
}