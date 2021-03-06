#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <climits>
#include <cmath>
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int main()
{
    double t, s, q, d;
    int ans = 0;
    cin >> t >> s >> q;
    for (d = s; d < t;) {
        d += s * (q - 1);
        s = d;
        ans++;
    }
    cout << ans << endl;
    return 0;
}