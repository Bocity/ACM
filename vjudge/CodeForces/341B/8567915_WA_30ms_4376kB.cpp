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
int a[200000], b[200000], n, m, sum = 0, ans, maxx;
int f[200000] = {0};
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ans = 0;
    // m = n;
    // ans = 0;
    // for (int i = 1; i <= n; i++) {
    //     f[i] = 1;
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= i; j++)
    //         if (a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
    // }
    // for (int i = 1; i <= n; i++) {
    //     maxx = max(maxx, f[i]);
    // }
    // // for (int i = 1; i <= n; i++) {
    // //     cout << f[i] << " ";
    // // }
    for (int i = 1; i <= n; i++)
        if (a[i] <= i) ans++;
    cout << ans;
    return 0;
}