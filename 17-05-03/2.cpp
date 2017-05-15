#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
void ex_gcd(ll a, ll b, ll &d, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0, d = a;
    } else {
        ex_gcd(b, a % b, d, y, x), y -= x * (a / b);
    }
}

int main() {
    ios::sync_with_stdio(false);
    ll i, n, a1, r1, a2, r2, ans, a, b, c, d, x0, y0;
    while (cin >> n) {
        bool ifhave = 1;
        cin >> a1 >> r1;
        for (i = 1; i < n; i++) {
            cin >> a2 >> r2;
            a = a1;
            b = a2;
            c = r2 - r1;
            ex_gcd(a, b, d, x0, y0);
            if (c % d != 0) {
                ifhave = 0;
            }
            int t = b / d;
            x0 = (x0 * (c / d) % t + t) % t;
            r1 = a1 * x0 + r1;
            a1 = a1 * (a2 / d);
        }
        if (!ifhave) {
            cout << -1 << "\n";
            continue;
        } else {
            cout << r1 << "\n";
        }
    }

    return 0;
}