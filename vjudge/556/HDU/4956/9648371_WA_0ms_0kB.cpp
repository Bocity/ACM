#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool check(ll n) {
    int odd = 0, even = 0;
    int cnt = 0;
    while (n) {
        if ((++cnt) & 1)
            odd += n % 10;
        else
            even += n % 10;
        n /= 10;
    }
    if (odd == even + 3) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    int t;
    ll l, r;
    cin >> t;
    while (t--) {
        cin >> l >> r;
        int ans = -1;
        for (ll i = l; i <= r; i++) {
            if (i % 11 == 3) {
                for (ll j = i; j <= r; j += 11) {
                    if (!check(j)) {
                        ans = j;
                        break;
                    }
                }
                break;
            }
        }
        cout << ans << endl;
    }
}