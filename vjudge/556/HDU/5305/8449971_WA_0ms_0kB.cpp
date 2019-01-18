#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <deque>
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
vector<int> mp[10];
bool vis[10];
int color[10];
int cnt;
int st[10];
bool dfs(int p) {
    if (mp[p].size() & 1) return false;
    for (auto j : mp[p]) {
        if (vis[j]) {
            if (color[j] == color[p]) return false;
            else return true;
        }
        vis[j] = true;
        if (color[p] == 1) {
            color[j] = 2;
            if (!dfs(j)) return false;
        }
        else if (color[p] == 2) {
            color[j] = 1;
            if (!dfs(j)) return false;
        }
    }
    return true;
}
int getfa(int p) {
    while(p != st[p]) {
        p = st[p];
    }
    return p;
}
int main() {
    ios::sync_with_stdio(false);
    int t, x, y, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        mems(vis, false);
        mems(color, 0);
        for (int i = 1; i <= n; i++) {
            mp[i].clear();
            st[i] = i;
        }
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            mp[x].push_back(y);
            mp[y].push_back(x);
            if (getfa(x) != getfa(y)) {
                if (x > y) swap(x, y);
                st[x] = getfa(y);
            }
        }
        bool flag = false;
        color[1] = 1;
        vis[1] = true;
        int temp = 0;
        for (int i = 1; i <= n; i++) {
            if (st[i] == i) temp++;
        }
        if (!dfs(1) || temp > 1) flag = true;
        if (flag)
            cout << 0 << endl;
        else {
            cout << (1 << (m - n + 1)) << endl;
        }
    }
    return 0;
}