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

#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
vector<pii> v;
map<int, int> mp, _mp;
int main() {
    ios::sync_with_stdio(false);
    ll t, a, b, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        v.clear();
        mp.clear();
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            v.push_back(pii(a, b));
        }
        bool fg = false;
        for (int i = 0; i < v.size(); i++) {
            _mp.clear();
            for (int j = i + 1; j < v.size(); j++) {
                a = v[i].first - v[j].first;
                b = v[i].second - v[j].second;
                if (a * b >= 0 && !(a == 0 && b == 0) && _mp[abs(a + b)] == 0) {
                    _mp[abs(a + b)] = 1;
                    if (++mp[abs(a + b)] > 1) {
                        fg = true;
                        break;
                    }
                }
            }
        }
        if (fg)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}