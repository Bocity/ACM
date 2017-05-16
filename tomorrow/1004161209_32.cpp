#include <cstring>
#include <iostream>
using namespace std;
int n, m, a[500][500], f[10000], x, y, z;
int main() {
    cin >> n >> m;
    memset(a, -1, sizeof(a));
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> z;
        a[x][y] = z;
        a[y][x] = z;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++) {
                if (a[j][i] != -1 && a[i][k] != -1)
                    if (a[j][k] > a[j][i] + a[i][k] || a[j][k] == -1) a[j][k] = a[j][i] + a[i][k];
            }
    long long maxx = -10e8 + 7;
    long long minn = 10e8 + 7;
    long long ans = 0, ans2 = 0;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) cout << a[i][j] << " ";
    //     cout << "\n";
    // }
    bool flag = false;
    for (int j = 2; j <= n; j++)
        if (a[1][j] == -1) flag = true;
    if (flag) {
        cout << 0;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        maxx = -10e8 + 7;
        ans = 0;

        for (int j = 1; j <= n; j++) {
            if (i != j && maxx < a[i][j]) {
                maxx = a[i][j];
                ans = i;
            }
        }
        if (minn > maxx) {
            minn = maxx;
            ans2 = ans;
        }
    }

    cout << ans2 << " " << minn;
}
/*
6 11
3 4 70
1 2 1
5 4 50
2 6 50
5 6 60
1 3 70
4 6 60
3 6 80
5 1 100
2 4 60
5 2 80

6 5
1 2 3
2 3 4
3 4 5
4 5 6
1 3 2
*/
