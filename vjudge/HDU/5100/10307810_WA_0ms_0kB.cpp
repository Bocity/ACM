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
ll n, m, max2, max1, max3;
void stay() {
    cin >> n >> m;
    if (m > n) {
        cout << 0 << endl;
        return;
    }
    if (n % m == 0) {
        cout << n * n << endl;
        return;
    }
    REP(i, 1, 200) {
        if ((n * n - i * i) % m == 0 && (n * n - i * i) % (4 * m) == 0) {
            max3 = n * n - i * i;
            break;
        }
    }
    max1 = m * n * (n / m) + (n - (n / m) * m) * m * (n / m);
    // max3 = m * (m + 2) + (n * n - n * n / (m * (m + 2)) * (m * (m + 2))) / m * m;
    // cout << max3 << endl;
    max2 = (n - m) * m * 4;
    cout << max(max(max2, max1), max3) << endl;
}
int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        stay();
    }
    return 0;
}