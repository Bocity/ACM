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
vector<ll> v1, v2;
int main() {
    ios::sync_with_stdio(false);
    ll t, n, m, k;
    int sum = 0;
    v2.push_back(0);
    REP(i, 1, 500) {
        v1.push_back(i * i);
        v2.push_back(sum += i);
    }
    while (cin >> n >> k) {
        int pos = lower_bound(all(v1), n) - v1.begin();
        pos = v1[pos - 1];
        if (k == 2 && pos == n - pos)
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
        }
    }
    return 0;
}