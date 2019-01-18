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
const int MAX = 100000 * 2;
const int INF = 1e9;
long long pow(long long a, long long b, long long p) { // return a^b %p
    long long t = 1;
    for (a %= p; b; b >>= 1LL, a = a * a % p)
        if (b & 1LL) t = t * a % p;
    return t;
}
int main() {
    ios::sync_with_stdio(false);
    ll n, m, ans;
    while (cin >> n >> m) {
        if (n & 1) {
            n = (n + 1) / 2;
            ans = pow(4, n, 3 * m) - 1;
            cout << (ans / 3 + m) % m << endl;
        } else {
            ans = pow(4, n / 2, 3 * m) - 1 + 3 * m;
            cout << (ans / 3 * 2 + m) % m << endl;
        }
    }
    return 0;
}