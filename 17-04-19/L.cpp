#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
ll cnt, s[100000], v, san[100000], n, a[100000];
ll lowbit(ll x) {
    return x & -x;
}
ll query(ll x) {
    ll ret = 0;
    while (x) {
        ret += s[x];
        x -= lowbit(x);
    }
    return ret;
}
void upd(ll x, ll y) {
    while (x <= cnt) {
        s[x] += v;
        x += lowbit(x);
    }
}
int main() {
    while (cin >> n) {
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            san[cnt++] = a[i];
        }
        sort(san + 1, san + 1 + n);
        cnt = unique(san + 1, san + cnt + 1) - san - 1;
        for (int i = 1; i <= n; i++) a[i] = lower_bound(san + 1, san + cnt + 1, a[i]) - san;
        memset(s, 0, sizeof(s));
        ll sum1 = 0, sum2 = 0;
        for (int i = n; i >= 1; i--) {
        }
    }
    return 0;
}