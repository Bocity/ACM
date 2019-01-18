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
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int n, m, x, y;
vector<int> a[10050];
int color[10050];
int vis[10050];
void addedge(int i, int j) {
    a[i].push_back(j);
    a[j].push_back(i);
}
bool judge(int n) {
    for (int i = 1; i <= n; i++) {
        if (n == 1) {
            if (color[i] == 0 || vis[i] == 0) continue;
        } else {
            if (vis[i] == 0) continue;
        }
        vis[i] = 1;
        if (n == 2) color[i] = 1;
        queue<int> q;
        while (!q.empty()) q.pop();
        q.push(i);
        while (!q.empty()) {
            int x0 = q.front();
            q.pop();
            for (auto t : a[x0]) {
                if (color[t] == 0) {
                    color[t] = 3 - color[x0];
                    vis[t] = 1;
                    q.push(t);
                    continue;
                }
                if (!vis[t] && color[t] != 0 && color[t] == 3 - color[x0]) {
                    vis[t] = 1;
                    q.push(t);
                    continue;
                }
                if (color[t] != 0 && color[t] != 3 - color[x0]) {
                    vis[t] = 1;
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> m >> x >> y) {
        for (int i = 1; i <= n; i++) {
            a[i].clear();
        }
        mems(color, 0);
        mems(vis, 0);
        for (int i = 1; i <= m; i++) {
            int aa, bb;
            cin >> aa >> bb;
            addedge(aa, bb);
        }
        for (int i = 1; i <= x; i++) {
            int xx;
            cin >> xx;
            color[xx] = 1;
        }
        for (int i = 1; i <= y; i++) {
            int yy;
            cin >> yy;
            color[yy] = 1;
        }
        int flag = judge(1);
        for (int i = 1; i <= n; i++) {
            if (color[i] == 0) {
                if (a[i].empty()) {
                    flag = 0;
                    break;
                }
            }
        }
        if (!flag) {
            cout << "NO" << endl;
            continue;
        }
        flag = judge(2);
        if (!flag) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}