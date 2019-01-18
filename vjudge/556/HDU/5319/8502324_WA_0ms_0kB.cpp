#include <algorithm>
#include <climits>
#include <cmath>
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
int mp[60][60];
int n, t;
bool vis1[60][60];
bool vis2[60][60];
int dfs() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp = 3;
            if (!vis1[i][j]) {
                for (int x = 0; x + i < n && x + j < n; x++) {
                    temp = min(temp, mp[x + i][x + j]);
                }
                if (temp == 1 || temp == 3) {
                    for (int x = 0; x + i < n && x + j < n; x++) {
                        vis1[x + i][x + j] = true;
                        mp[x + i][x + j] -= 1;
                    }
                    ans++;
                }
            }
            temp = 3;
            if (!vis2[i][j]) {
                for (int x = 0; x + i >= 0 && j - x < n; x--) {
                    temp = min(temp, mp[i + x][j - x]);
                }
                if (temp == 2 || temp == 3) {
                    for (int x = 0; x + i >= 0 && j - x < n; x--) {
                        vis2[x + i][j - x] = true;
                        mp[x + i][j - x] -= 2;
                    }
                    ans++;
                }
            }
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    char temp;
    cin >> t;
    while (t--) {
        cin >> n;
        mems(vis1, false);
        mems(vis2, false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> temp;
                mp[i][j] = (temp == 'R' ? 1 : (temp == 'B' ? 2 : (temp == 'G' ? 3 : 0)));
            }
        }
        cout << dfs() << endl;
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << mp[i][j];
        //     }
        //     cout << endl;
        // }
    }
    return 0;
}