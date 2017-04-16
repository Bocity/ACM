#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
ll n, dd = 0, a[100005], b[100005], c[100005], d[100005];
int main() {
    cin >> n;
    memset(c, 0, sizeof(c));
    memset(b, 0, sizeof(b));
    memset(d, 0, sizeof(d));

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = abs(a[i] - a[i - 1]);
    }
    // for (int i = 1; i <= n; i++) cout << b[i] << " ";
    // cout << endl;
    ll sum1 = 0, sum2 = 0, maxx = -(1e9);
    for (int i = 2; i <= n; i++) {
        // cout << dd << " " << maxx << " ";
        maxx = max(maxx, dd);
        if (dd < 0) {
            dd = 0;
        }
        if (i % 2 == 0) {
            dd += b[i];
        } else {
            dd -= b[i];
        }
    }
    maxx = max(maxx, dd);
    // cout << endl;
    dd = 0;
    for (int i = 3; i <= n; i++) {
        maxx = max(maxx, dd);
        if (dd < 0) {
            dd = 0;
        }
        if (i % 2) {
            dd += b[i];
        } else {
            dd -= b[i];
        }
    }
    maxx = max(maxx, dd);
    cout << maxx;
    return 0;
}