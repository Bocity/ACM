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
int a[101000];
int root[101000];
vector<int> v[101000];
int uni(int u) {
    return u == root[u] ? u : root[u] = uni(root[u]);
}
int main() {
    ios::sync_with_stdio(false);
    ll n;
    while (cin >> n) {
        REP(i, 1, n + 1) {
            v[i].clear();
            root[i] = i;
            cin >> a[i];
        }
        int x, y;
        REP(i, 1, n + 1) {
            x = uni(i), y = uni(a[i]);
            if (x != y) {
                root[x] = y;
            }
        }
        REP(i, 1, n + 1) {
            v[root[i]].push_back(i);
        }
        REP(i, 1, n + 1) {
            if (v[i].size()) {
                sort(all(v[i]));
            }
        }
        sort(v + 1, v + n + 1);
        REP(i, 1, n + 1) {
            if (v[i].size()) {
                cout << "(" << v[i][0];
                for (int j = 1; j < v[i].size(); j++) cout << " " << v[i][j];
                cout << ")";
            }
        }
        cout << endl;
    }
    return 0;
}