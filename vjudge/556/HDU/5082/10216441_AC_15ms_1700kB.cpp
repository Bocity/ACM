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
int main() {
#ifdef FUCK
// freopen("data.in", "r", stdin);
// freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    string a, b;
    while (cin >> a >> b) {
        REP(i, 0, a.size()) {
            if (a[i] == '_') {
                REP(j, i + 1, a.size()) cout << a[j];
                break;
            }
        }
        cout << "_small_";
        REP(i, 0, b.size()) {
            if (b[i] == '_') {
                REP(j, i + 1, b.size()) cout << b[j];
                break;
            }
        }
        cout << endl;
    }
}