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
const ll INF = 0x3f3f3f3f;
int a[20000];
int posb[20];
int main() {
    ios::sync_with_stdio(false);
    ll t, n, m;
    while (cin >> n) {
        ll sum = 0;
        REP(i, 1, n + 1) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a + 1, a + 1 + n);
        if (a[(n + 1) / 2] * n <= sum) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}