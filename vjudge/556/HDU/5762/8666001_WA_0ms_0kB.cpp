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
map<int, int> mp;
map<pii, bool> __mp;
int main() {
    ios::sync_with_stdio(false);
    ll t, a, b, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        v.clear();
        mp.clear();
        __mp.clear();
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            if (__mp[pii(a, b)] == 0) {
                __mp[pii(a, b)] = 1;
                v.push_back(pii(a, b));
            }
        }
        sort(v.begin(), v.end());
        bool fg = false;
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                a = v[i].first - v[j].first;
                b = v[i].second - v[j].second;
                if (b < 0)
                    if (mp[a + b]) {
                        fg = true;
                        break;
                    } else {
                        mp[a + b] = 1;
                    }
            }
            if (fg) break;
        }
        if (fg)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}