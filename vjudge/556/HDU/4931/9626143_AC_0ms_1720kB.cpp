#include <algorithm>
#include <bitset>
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
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int a[10];
int main() {
#ifdef FUCK
// freopen("data.in", "r", stdin);
// freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        REP(i, 1, 7) {
            cin >> a[i];
        }
        sort(a + 1, a + 7);
        if (a[5] + a[6] > a[3] + a[4] + a[2]) {
            cout << "Grandpa Shawn is the Winner!" << endl;
        } else {
            cout << "What a sad story!" << endl;
        }
    }
}