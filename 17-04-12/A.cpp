#include <iostream>
using namespace std;
int n, k, ans, x;
int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x % k == 0)
            ans += x / k;
        else
            ans += x / k + 1;
    }
    if (ans % 2 == 0)
        cout << ans / 2;
    else
        cout << ans / 2 + 1;
    return 0;
}