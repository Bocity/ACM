#include <bits/stdc++.h>
using namespace std;
const int N = 400000;
typedef long long ll;
ll a[N];
queue<ll> q;
queue<ll> nq;
int n, k;
bool solve(int m) {
    while (!q.empty()) {
        q.pop();
    }
    while (!nq.empty()) {
        nq.pop();
    }
    if (k == 1 && n >= m) return true;
    for (int i = 0; i < m; i++) {
        q.push(a[i]);
    }
    int step = 1;
    for (int i = m; i < n; i++) {
        if (!q.empty()) {
            if (a[i] >= 2ll * q.front()) {
                q.pop();
                nq.push(a[i]);
            }
            if (q.empty()) {
                swap(q, nq);
                step++;
            }
        } else
            break;
    }

    if (step >= k)
        return true;
    else
        return false;
}
int main() {
    ios::sync_with_stdio(false);
    ll t, cnum = 1;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        ll ans = 0;
        int l = 0, r = n / k;

        while (l <= r) {
            int mid = (l + r) / 2;
            bool can = solve(mid);
            if (can) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << "Case #" << cnum++ << ": ";
        cout << r << endl;
    }
}