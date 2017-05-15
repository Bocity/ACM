#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll a[100005], f[100005], n;
int main() {
    cin >> n;
    ll maxx = -1e9;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] >= a[i - 1])
            f[i] = f[i - 1] + 1;
        else
            f[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        maxx = max(maxx, f[i]);
    }
    cout << maxx;
    return 0;
}