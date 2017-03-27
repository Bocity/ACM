#include <iostream>
using namespace std;
int n, m, ans, a[2000][2000] = {0}, b[2000][2000], c[2000][2000], d[2000][2000], e[2000][2000];
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int i = 1; i <= m; i++) c[n + 1][i] = 1;
    for (int i = 1; i <= n; i++) b[i][m + 1] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m + 1; j++) {
            if (a[i][j] == 1)
                b[i][j] = j;
            else
                b[i][j] = b[i][j - 1];
        }
    for (int j = 1; j <= m; j++)
        for (int i = 1; i <= n + 1; i++) {
            if (a[i][j] == 1)
                c[i][j] = i;
            else
                c[i][j] = c[i - 1][j];
        }
    for (int i = n; i >= 1; i--) d[i][0] = 1;
    for (int i = m; i >= 1; i--) e[0][i] = 1;
    for (int i = n; i >= 1; i--) d[i][m + 1] = m + 1;
    for (int i = m; i >= 1; i--) e[n + 1][i] = n + 1;

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 0; j--) {
            if (a[i][j] != 0)
                d[i][j] = j;
            else
                d[i][j] = d[i][j + 1];
        }
    for (int j = 1; j <= m; j++)
        for (int i = n; i >= 0; i--) {
            if (a[i][j] != 0)
                e[i][j] = i;
            else
                e[i][j] = e[i + 1][j];
        }

    for (int i = 1; i <= n + 1; i++)
        for (int j = 1; j <= m + 1; j++)
            if (a[i][j] == 1) {
                ans += j - b[i][j - 1] - 1;
                ans += i - c[i - 1][j] - 1;
            }
    // // cout << ans;
    // for (int i = 0; i <= n + 1; i++) {
    //     for (int j = 0; j <= m + 1; j++) {
    //         cout << e[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for (int i = n; i >= 0; i--)
        for (int j = m; j >= 0; j--)
            if (i + j != 0)
                if (a[i][j] == 1) {
                    ans += e[i + 1][j] - i - 1;
                    ans += d[i][j + 1] - j - 1;
                }
    cout << ans;
    return 0;
}
