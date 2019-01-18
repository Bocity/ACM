#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int c[25], vis[25];
typedef long long ll;
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    ll ret = exgcd(b, a % b, x, y), tmp = y;
    y = x - a / b * y;
    x = tmp;
    return ret;
}
ll inv(ll a, ll mod) {
    ll x, y;
    ll gcd = exgcd(a, mod, x, y);
    if (gcd != 1) return -1;
    return x < 0 ? x + mod : x;
}
struct modeq {
    ll a, mod;
    modeq() {}
    modeq(ll a, ll mod)
        : a(a)
        , mod(mod) {}

    modeq crt(const modeq &p) const { // 保证所有运算在 lcm + max(p.moder, moder) 的数据范围内实现，注意不要让模数为 0
        modeq p1 = *this, p2 = p;
        if (p1.mod < p2.mod) std::swap(p1, p2);
        ll x, y;
        ll gcd = exgcd(p1.mod, p2.mod, x, y);
        if ((p2.a - p1.a) % gcd) return modeq(0, 0);
        ll lcm = p1.mod / gcd * p2.mod;
        ll ans = (p2.a - p1.a) / gcd;
        ans = 1ll * ans * x % (p2.mod / gcd) * p1.mod;
        ans += p1.a;
        ans += ans < 0 ? lcm : ans >= lcm ? -lcm : 0;
        return modeq(ans, lcm);
    }
} eq[25];
// void ex_gcd(int a, int b, int &d, int &x, int &y) {
//     if (!b) {
//         d = a;
//         x = 1;
//         y = 0;
//     } else {
//         ex_gcd(b, a % b, d, y, x);
//         y -= (a / b) * x;
//     }
// }
// int CRT(int n) {
//     int c = a[1], l = m[1];
//     int d, x, y;
//     for (int i = 2; i <= n; i++) {
//         ex_gcd(l, m[i], d, x, y);
//         if ((a[i] - c) % d) return -1;
//         int tt = m[i] / d;
//         x = (a[i] - c) / d * x % (m[i] / d);
//         c += l * x;
//         l = l / d * m[i];
//         c %= l;
//     }
//     return (c + l) % l ? (c + l) % l : l;
// }
int main() {
    int t;
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) {
        int tmp, n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> tmp;
            c[tmp] = i;
        }
        memset(vis, 0, sizeof(vis));
        int j = 0;
        for (int i = 1; i <= n; i++) {
            int k = 0;
            while (j != c[i]) {
                j++;
                if (j > n) j = 1;
                if (!vis[j]) k++;
            }
            vis[c[i]] = 1;
            eq[i].a = k;
            eq[i].mod = n - i + 1;
            eq[i].a %= eq[i].mod;
            // a[i] = k;
            // m[i] = n - i + 1;
            // a[i] %= m[i];
        }
        for (int i = 2; i <= n; ++i) {
            eq[1] = eq[1].crt(eq[i]);
            if (eq[1].mod == 0) break;
            //cout <<eq[1].a << " " << eq[1].mod << "  " << eq[i].a << " " << eq[i].mod << endl;
        }
        if (eq[1].mod != 0)
            printf("%lld\n", eq[1].mod);
        else
            printf("Creation August is a SB!\n");
    }
    return 0;
}