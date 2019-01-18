#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100;
vector<ll> v;
int main() {
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        v.clear();
        ll a, b;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            for (int j = 0; j < b; j++) v.push_back(a);
        }
        sort(v.begin(), v.end());
        ll sum2 = 0, sum1 = 0;
        ll ans = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            if (sum2 < 0) break;
            sum1 += v[i];
            sum2 += sum1;
            ans = max(ans, sum2);
        }
        cout << ans << endl;
    }
}