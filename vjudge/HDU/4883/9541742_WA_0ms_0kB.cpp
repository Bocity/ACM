#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
long long sum[10000];
int main() {
    // ios::sync_with_stdio(false);
    long long T, n, ans, anss;
    cin >> T;
    while (T--) {
        memset(sum, 0, sizeof sum);
        ans = 0;
        cin >> n;
        int num, h, m, l, r;
        for (int i = 1; i <= n; i++) {
            cin >> num;
            scanf("%d:%d", &h, &m);
            l = h * 100 + m;
            scanf("%d:%d", &h, &m);
            r = h * 100 + m;
            sum[l] += num;
            sum[r] -= num;
        }
        ans = 0, anss = 0;

        for (int i = 0; i <= 5000; i++) {
            if (ans + sum[i] >= ans) {
                ans += sum[i];
                anss = max(ans, anss);
            } else {
                anss = max(anss, ans);
                ans = 0;
            }
        }
        cout << anss << endl;
    }
    return 0;
}