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
    int cas, n, m, sum, ans, temp, a[30];
    cin >> cas;
    while (cas--) {
        cin >> n;
        ans = 0;
        while (n--) {
            cin >> m;
            sum = 0;
            for (int i = 0; i < m; i++) cin >> a[i];
            sort(a, a + m);
            for (int i = 0; i < m; i++) {
                sum += 20 - a[i] - (m - i - 1);
            }
            temp = (sum & 1) ? 1 : 0;
            ans ^= temp;
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}