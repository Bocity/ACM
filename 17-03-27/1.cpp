#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
long long a[100000], sum1, sum2, sum, n;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    sum1 = sum2 = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum2 += a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; i--) {
        sum1 += (2 * i - 1 - n) * a[i];
    }
    // for (int i = 1; i < n; i++) {
    //     for (int j = i + 1; j <= n; j++) sum1 += abs(a[j] - a[i]);
    // }
    sum1 *= 2;
    sum = sum1 + sum2;
    long long p = __gcd(n, sum);
    cout << sum / p << " " << n / p;
    return 0;
}