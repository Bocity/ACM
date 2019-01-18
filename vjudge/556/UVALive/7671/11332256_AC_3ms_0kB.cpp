#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
int a[N];
int dp1[N], dp2[N];
int main() {
    ios::sync_with_stdio(false);
    int t, n;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[n + i] = a[i];
        }
        memset(dp1, 0, sizeof dp1);
        memset(dp2, 0, sizeof dp2);
        dp1[0] = 1, dp2[0] = 1;
        int ans = 0;
        for (int i = 1; i < 2 * n; i++) {
            dp1[i] = dp2[i] = 1;
            if (a[i] > a[i - 1]) dp1[i] = max(dp1[i], dp1[i - 1] + 1);
            if (a[i] < a[i - 1]) dp2[i] = max(dp2[i], dp2[i - 1] + 1);
            ans = max(dp1[i], max(dp2[i], ans));
        }
        cout << ans - 1 << endl;
    }
}