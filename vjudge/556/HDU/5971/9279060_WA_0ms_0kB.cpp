#include <cstring>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
int a[1005][1005];
int vis[1005];
int vis1[1005];
int n, m, x, y;
int bfs(int xy, int flag) {
    queue<int> q;
    while (!q.empty()) {
        q.pop();
    }
    q.push(xy);
    while (!q.empty()) {
        xy = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (a[i][xy] == 1 || a[xy][i] == 1) {
                if (vis[i] == 0) {
                    q.push(i);
                    vis[i] = 3 - vis[xy];
                } else if (vis[i] != 3 - vis[xy]) {
                    return 0;
                } else if (vis[i] == 3 - vis[xy]) {
                    continue;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            // cout << "xinlenidexie " << i << endl;
            return 0;
        }
    }
    return 1;
}
int bfs1(int xy, int flag) {
    queue<int> q;
    while (!q.empty()) {
        q.pop();
    }
    q.push(xy);
    while (!q.empty()) {
        xy = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (a[i][xy] == 1 || a[xy][i] == 1) {
                if (vis1[i] == 0) {
                    q.push(i);
                    vis1[i] = 3 - vis1[xy];
                } else if (vis1[i] != 3 - vis1[xy]) {
                    return 0;
                } else if (vis1[i] == 3 - vis1[xy]) {
                    continue;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!vis1[i]) {
            // cout << "xinlenidexie " << i << endl;
            return 0;
        }
    }
    return 1;
}

int main() {
    int flag1, flag2;
    int flag3;
    while (cin >> n >> m >> x >> y) {
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        memset(vis1, 0, sizeof(vis1));
        int xx, yy;
        for (int i = 0; i < m; i++) {
            cin >> xx >> yy;
            a[xx - 1][yy - 1] = 1;
            a[yy - 1][xx - 1] = 1;
        }
        for (int i = 0; i < x; i++) {
            cin >> xx;
            vis[xx - 1] = 1;
        }
        for (int i = 0; i < y; i++) {
            cin >> yy;
            vis[yy - 1] = 2;
        }
        if (n == 1 && x + y == 1) {
            cout << "YES" << endl;
            continue;
        } else if (n == 1 && x + y == 0) {
            cout << "NO" << endl;
            continue;
        }
        flag1 = flag2 = 0;
        flag3 = 1;
        for (int i = 0; i < n; i++) {
            vis1[i] = vis[i];
        }
        if (x + y == n) {
            flag1 = bfs(0, vis[0]);
            flag2 = bfs1(0, vis[0]);
        } else {
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    vis[i] = 1;
                    flag1 = bfs(i, vis[i]);
                    vis1[i] = 2;
                    flag2 = bfs1(i, vis1[i]);
                    flag3 = 0;
                    break;
                }
            }
        }
        if (flag1 || flag2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
