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
int a[200000], b[200000], n, m, minn;
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(b, 0, sizeof(b));
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[i] < a[j]) {
                swap(a[i], a[j]);
                b[a[i]]++;
                b[a[j]]++;
            }
    minn = 2 * n + 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] < minn) minn = a[i];
    }
    cout << n - minn;
    return 0;
}