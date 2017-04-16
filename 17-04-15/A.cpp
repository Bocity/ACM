#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
ll ans, maxx, x, m, n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        maxx = max(maxx, (long long) 0) + x;
        ans = max(maxx, ans);
    }
    cout << ans;
    return 0;
}