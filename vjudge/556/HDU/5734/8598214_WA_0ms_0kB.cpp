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
    unsigned ll a[100005];
    unsigned ll sum, cnt, n, g;
    ll temp;
    while (t--) {
        cin >> n;
        sum = cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] < 0) a[i] = -a[i];
            sum += a[i];
        }
        for (int i = 0; i < n; i++) {
            cnt += a[i] * a[i];
        }
        cnt = cnt * n - sum * sum;
        g = __gcd(cnt, n);
        if (cnt == 0)
            cout << "0/1" << endl;
        else
            cout << cnt / g << "/" << n / g << endl;
    }
    return 0;
}