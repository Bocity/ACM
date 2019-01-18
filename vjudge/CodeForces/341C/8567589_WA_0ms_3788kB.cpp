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
bool x[200000] = {0};
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    m = n;
    ans = 0;
    for (int j = 1; j <= n; j++) {
        maxx = 0;
        sum = 0;
        for (int i = 1; i <= n; i++) {
            if (!x[i] && maxx < a[i]) {
                maxx = a[i];
                x[i] = true;
                sum++;
            }
        }
        ans = max(ans, sum);
    }

    cout << ans;
    return 0;
}