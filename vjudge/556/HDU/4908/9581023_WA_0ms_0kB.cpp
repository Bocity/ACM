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
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            cin >> temp;
            if (temp == m) {
                t = i;
            }
        }
        t = min(t - 1, n - t);
        cout << t + 1 << endl;
    }
    return 0;
}