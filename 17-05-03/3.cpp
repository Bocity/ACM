#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll k, m, n;
ll a[10000], r[10000];
void ex_gcd(ll a, ll b, ll &d, ll &x, ll &y) {
    if (b == 0) {
        d = a;
        y = 0;
        x = 1;
        return;
    } else {
        ex_gcd(b, a % b, d, y, x), y -= a / b * x;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> k;
    // cin>>a[][]
    for (int i = 1; i <= k; i++) {
        cin >> a[i] >> r[i];
    }
    for (int i = 2; i <= k; i++) {
        ll x, y, d;
        ex_gcd(a[i], r[i], d, x, y);
        ll ans, sum;
        ans = r[i] - r[1];

        ans = x *
    }
    return 0;
}