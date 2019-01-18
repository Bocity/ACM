#include <iostream>
using namespace std;

typedef long long ll;

ll bin_search(ll l, ll r, ll m, ll n) {
    ll mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if ((m / (double) n <= mid) || (m - 1001) / (double) n < mid)
            r = mid - 1;
        else {
            l = mid + 1;
        }
    }
    return l;
}
ll n, m, l = 1, a[1000005] = {0}, N;
int main() {
    cin >> n;
    N = n;
    m = 4 * (n + 1) * (n + 1);
    while (l < N) {
        ll x = 1;
        x = bin_search(1, m, m, n);
        while ((m - (x * n)) * (m - (x * n)) % n) x--;
        a[l] = x;
        m = (m - (x * n)) * (m - (x * n));
        n--;
        l++;
    }
    a[N] = m - 2;
    for (long long i = N; i >= 1; i--) {
        cout << a[i] << "\n";
    }
    return 0;
}