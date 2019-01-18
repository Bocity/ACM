#include <algorithm>
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
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
bool vis[100010];
int arr[2][100010];
const int mid = 50000;
int main() {
    ios::sync_with_stdio(false);
    int n, m, t, temp;
    while (cin >> n >> m) {
        mems(arr, 0);
        mems(vis, false);
        for (int i = 1; i <= n; i++) {
            cin >> temp;
            if (temp == m) {
                t = i;
            } else if (temp < m) {
                vis[i] = true;
            }
        }
        int cnt = mid;
        int ans = 0;
        arr[0][cnt] = arr[1][cnt] = 1;
        for (int i = t + 1; i <= n; i++) {
            if (i & 1) {
                if (vis[i]) {
                    arr[0][++cnt]++;
                } else {
                    arr[0][--cnt]++;
                }
            } else {
                if (vis[i]) {
                    arr[1][++cnt]++;
                } else {
                    arr[1][--cnt]++;
                }
            }
            if (((i - t + 1) & 1) && cnt == mid) ans++;
        }
        cnt = mid;
        for (int i = t - 1; i > 0; i--) {
            if (i & 1) {
                if (!vis[i]) {
                    ans += arr[0][++cnt];
                } else {
                    ans += arr[0][--cnt];
                }
            } else {
                if (!vis[i]) {
                    ans += arr[1][++cnt];
                } else {
                    ans += arr[1][--cnt];
                }
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}