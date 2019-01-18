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
bool vis[200010];
int arr[200010];
int main() {
    ios::sync_with_stdio(false);
    int n, m, t, temp;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        mems(vis, false);
        mems(arr, 0);
        REP(i, n) {
            cin >> temp;
            vis[temp] = true;
        }
        int pre = 200010;
        for (int i = 200010; i >= 0; i--) {
            if (vis[i]) {
                arr[i] = pre;
            } else {
                pre = i;
                arr[i] = pre;
            }
        }
        REP(i, m) {
            cin >> temp;
            cout << arr[temp] << endl;
        }
    }
    return 0;
}