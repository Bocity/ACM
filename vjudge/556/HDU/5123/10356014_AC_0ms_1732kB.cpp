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
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(false);
    int t, n, temp;
    cin >> t;
    pii a[400];
    while (t--) {
        cin >> n;
        REP(i, 0, 300) a[i].second = -i, a[i].first = 0;
        REP(i, 0, n) {
            cin >> temp;
            a[temp].first++;
        }
        sort(a + 1, a + 300, greater<pii>());
        cout << -a[1].second << endl;
    }
    return 0;
}