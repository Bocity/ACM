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
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int N = 110000;
void dfs() {}
int main() {
    ios::sync_with_stdio(false);
    int t, cas, n;
    cin >> t;
    REP(cas, 1, t + 1) {
        cin >> n;
        ll ans = 0, temp;
        REP(i, 0, n) {
            cin >> temp;
            if (temp != 1) ans ^= temp;
        }
        cout << "Case " << cas << ": " << (ans == 0 ? "Bob" : "Alice") << endl;
    }
    return 0;
}