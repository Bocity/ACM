#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define REP(i, x, n) for (int i = (x); (i) < (n); i++)
#define PER(i, x, n) for (int i = (n) -1; (i) >= (x); i--)
#define DE puts("---------")
#define sqr(x) ((x) * (x))
using namespace std;
typedef long long ll;
typedef bitset<4005> Bitset;
// void stay(int n) {}
ll a, b, a1, b1, max1, max2, max3, ans;
ll f[100], g[100], p[100];
int main() {
    ios::sync_with_stdio(0);
    ans = 0;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << endl;
        return 0;
    }
    ll a1;
    a1 = a;
    int i = 0, j = 0;
    while (a1 > 0) {
        if (a1 & 1) {
            max1 = i;
        }
        f[i] = a1 & 1;
        a1 >>= 1;
        i++;
    }
    b1 = b;
    while (b1 > 0) {
        if (b1 & 1) {
            max2 = j;
        }
        g[j] = b1 & 1;
        b1 >>= 1;
        j++;
    }
    // PER(i, 0, max1 + 1) {
    //     cout << f[i];
    // }
    // cout << endl;
    // PER(i, 0, max2 + 1) {
    //     cout << g[i];
    // }
    max3 = max2;
    if (max1 == max2) {
        while (g[max2] == f[max1]) {
            max2--;
            max1--;
        }

        REP(i, 0, max2) {
            ans += (ll) pow(2, i);
        }
        REP(i, max2, max3 + 1) {
            if (g[i] ^ f[i]) ans += pow(2, i);
        }
    } else {
        REP(i, 0, max2 + 1) {
            ans += (ll) pow(2, i);
        }
    }
    cout << ans << endl;
    return 0;
}
