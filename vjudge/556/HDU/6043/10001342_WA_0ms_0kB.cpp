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
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(false);
    ll n, m;
    while (cin >> n >> m) {
        if (m <= n)
            cout << m << endl;
        else {
            m -= n;
            m = m % (2 * (n - 1));
            if (m % (n - 1) == 0) {
                if (m / (n - 1) == 1) {
                    cout << n - 1 << endl;
                } else {
                    cout << n << endl;
                }
            } else {
                cout << m % (n - 1) << endl;
            }
        }
    }
    return 0;
}