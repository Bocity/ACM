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
pii a[210000];
int main() {
    ios::sync_with_stdio(false);
    int t, n, temp;
    cin >> t;
    while (t--) {
        cin >> n;
        n *= 2;
        REP(i, 0, n) {
            cin >> temp;
            a[i].first = temp;
            a[i].second = i & 1;
        }
        sort(a, a + n);
        int temp = 0, ans = 0;
        REP(i, 0, n) {
            if (a[i].second) {
                temp--;
            } else {
                temp++;
            }
            ans = max(ans, temp);
        }
        cout << ans << endl;
    }
    return 0;
}