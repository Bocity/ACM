// #include <bits/stdc++.h>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 110000;
ll t, n, arr[maxn], cnt[40];
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        memset(cnt, 0, sizeof cnt);
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        ll x = 0;
        ll y = n * (n - 1) / 2;
        ll tmp = 0;
        for (int i = 1; i <= n; i++) {
            for (int _ = 0; _ <= 33; _++) {
                if (arr[i] & (1ll << _)) {
                    x += (1ll << _) * (i - 1); //是1的话对前面所有的有贡献
                    cnt[_]++;
                } else {
                    x += (1ll << _) * cnt[_]; //是0的话只对前面为1的有贡献
                }
                if (x > y) {
                    tmp += x / y;
                    x = x % y;
                }
            }
        }
        ll g = __gcd(x, y);
        x /= g, y /= g;
        x = (x + tmp * y);
        g = __gcd(x, y);
        cout << x / g << "/" << y / g << endl;
    }

    return 0;
}