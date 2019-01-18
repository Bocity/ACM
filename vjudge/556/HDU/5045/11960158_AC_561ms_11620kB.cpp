#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N = 1100;
double a[20][N];
double dp[N][N];
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int cas = 1;
    int n, m;

    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) dp[i][j] = -1e18;

        dp[0][0] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < N; k++) {
                    if (!(k & (1 << j))) {
                        int tmp = k | (1 << j);
                        if (tmp == (1 << n) - 1) tmp = 0;
                        dp[i][tmp] = max(dp[i][tmp], dp[i - 1][k] + a[j][i]);
                        // if (dp[i][tmp] >= 0) {
                        //     cout << i << " " << tmp << " ";
                        //     cout << dp[i][tmp] << endl;
                        // }
                    }
                }
            }
        }

        double ans = *max_element(dp[m], dp[m] + N);
        cout << "Case #" << cas++ << ": " << fixed << setprecision(5) << ans << endl;
    }
}