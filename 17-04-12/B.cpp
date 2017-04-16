#include <cmath>
#include <iostream>
#include <map>
using namespace std;
long long b1, q, l, m, x, ans = 0;
int main() {
    map<long long, bool> p;
    cin >> b1 >> q >> l >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x;
        p[x] = true;
    }
    if (b1 == 0 && q == 0) {
        if (p[0])
            cout << 0;
        else
            cout << "inf";
        return 0;
    }
    if (q == 0 && b1 != 0) {
        if (abs(b1) > l) {
            cout << 0;
            return 0;
        }
        if (!p[b1] && p[0]) cout << 1;
        if (p[b1] && p[0]) cout << 0;
        if (!p[0]) cout << "inf";
        return 0;
    }
    if (b1 == 0 && q != 0) {
        if (!p[0])
            cout << "inf";
        else
            cout << 0;
        return 0;
    }
    if (q == 1) {
        if (p[b1] || abs(b1) > l)
            cout << 0;
        else
            cout << "inf";
        return 0;
    }
    if (q == -1) {
        if (abs(b1) > l) {
            cout << 0;
            return 0;
        }
        if (p[b1] && p[-b1])
            cout << 0;
        else
            cout << "inf";
        return 0;
    }

    while (abs(b1) <= l) {
        if (!p[b1]) ans++;
        b1 *= q;
    }
    cout << ans;
    return 0;
}