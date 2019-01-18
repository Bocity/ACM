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
ll n, m, max2, max1;
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
    max1 = (n / m) * (n / m);
    max2 = (n - m) * m * 4;
    cout << max(max1, max2) << endl;
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
