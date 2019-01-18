#include <iostream>
using namespace std;
typedef long long ll;

ll n, m, l = 1, a[1000005] = {0}, N;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    cout << "2\n";
    for (ll i = 2; i <= n; i++) {
        cout << i * (i + 1) * (i + 1) - (i - 1) << "\n";
    }
    return 0;
}