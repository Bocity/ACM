#include <algorithm>
#include <clocale>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
ll t, n, m, a[15], b[15];
ll extend_gcd(ll a, ll b, ll &x, ll &y) {
    ll d;
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        d = extend_gcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
}
ll CRT2(ll r[], ll w[], int n) {
    if (n == 1) {
        if (w[0] > r[0])
            return r[0];
        else
            return -1;
    }
    ll x, y, d;
    for (int i = 1; i < n; i++) {
        if (w[i] <= r[i]) return -1;
        d = extend_gcd(w[0], w[i], x, y);
        if ((r[i] - r[0]) % d != 0) return -1;
        ll t = w[i] / d;
        x = ((r[i] - r[0]) / d * x % t + t) % t;
        r[0] = x * w[0] + r[0];
        w[0] = w[0] * w[i] / d;
        r[0] = (r[0] % w[0] + w[0]) % w[0];
    }
    return r[0];
}
ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}
ll _lcm(ll *a, ll n) {
    ll ans = a[0];
    for (ll i = 1; i < n; ++i) ans = lcm(ans, a[i]);
    return ans;
}
int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        ll k = CRT2(b, a, m);
        if (k == -1){
            cout << 0 << endl;
            continue;
        }
        ll num = 0, s = _lcm(a, m);
        while (k <= n) {
            num++;
            k += s;
        }
        cout << num << endl;
    }
    return 0;
}