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
int r, c;
struct node {
    int x, y, s, far, up, down, left, right, exist, exist_t, bt;
} No[110];

int main() {
    ios::sync_with_stdio(false);
    int n, T, x, y, s;

    while (cin >> r >> c >> n >> T) {
        int mp[105][105];
        mems(mp, 0);
        for (int i = 1; i <= n; i++) {
            cin >> x >> y >> s;
            mp[x][y] = i;
            No[i].x = x;
            No[i].y = y;
            No[i].s = s;
            No[i].up = No[i].down = No[i].left = No[i].right = 0;
            No[i].far = 0;
            No[i].bt = -1, No[i].exist_t = 0, No[i].exist = 1;
        }
        cin >> x >> y;
        No[n + 1].x = x, No[n + 1].y = y, No[n + 1].s = 5, No[n + 1].far = 0;
        No[n + 1].up = No[n + 1].down = No[n + 1].left = No[n + 1].right = 0;
        No[n + 1].far = 0;
        No[n + 1].bt = -1, No[n + 1].exist_t = 0, No[n + 1].exist = 1;
        int X, Y, index;
        for (int t = 0; t <= T; t++) {
            for (int j = 1; j <= n + 1; j++) {
                X = No[j].x, Y = No[j].y;
                if(!No[j].exist) No[j].far++;
                if (No[j].exist && No[j].s > 4 && No[j].bt != t) {
                    mp[X][Y] = 0;
                    No[j].exist = 0, No[j].far = 1;
                    No[j].up = No[j].down = No[j].left = No[j].right = 1;
                    No[j].exist_t = t;
                }
                if (No[j].up && Y - No[j].far >= 0 && mp[X][Y - No[j].far]) {
                    index = mp[X][Y - No[j].far];
                    No[index].s++;
                    No[j].up = 0;
                    No[index].bt = t;
                }
                if (No[j].down && Y + No[j].far <= r && mp[X][Y + No[j].far]) {
                    index = mp[X][Y + No[j].far];
                    No[index].s++;
                    No[j].down = 0;
                    No[index].bt = t;
                }
                if (No[j].left && X - No[j].far >= 0 && mp[X - No[j].far][Y]) {
                    index = mp[X - No[j].far][Y];
                    No[index].s++;
                    No[j].left = 0;
                    No[index].bt = t;
                }
                if (No[j].right && X + No[j].far <= c && mp[X + No[j].far][Y]) {
                    index = mp[X + No[j].far][Y];
                    No[index].s++;
                    No[j].right = 0;
                    No[index].bt = t;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (No[i].exist) {
                cout << 1 << " " << No[i].s << endl;
            } else {
                cout << 0 << " " << No[i].exist_t << endl;
            }
        }
    }
    return 0;
}