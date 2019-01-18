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

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    ll a[100005], cnt, sum, n, g;
    while (t--) {
        cin >> n;
        ll nn = n;
        sum = cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] = abs(a[i]);
            sum += a[i];
        }
        g = __gcd(sum, n);
        sum /= g, n /= g;

        for (int i = 0; i < nn; i++) {
            cnt += pow(a[i] * n - sum, 2);
        }
        n *= n;
        g = __gcd(cnt, n);
        cout << cnt / g << "/" << n / g << endl;
    }
    return 0;
}