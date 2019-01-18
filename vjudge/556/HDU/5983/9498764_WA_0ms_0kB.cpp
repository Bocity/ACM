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
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

bool judge(const auto &v) {
    for (int i = 0; i < 6; i++) {
        int val = v[i][0];
        for (int j = 0; j < 4; j++) {
            if (val != v[i][j]) return false;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    int t, temp;
    cin >> t;
    while (t--) {
        vector<int> m[6];
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> temp;
                m[i].push_back(temp);
            }
        }
        if (judge(m)) {
            cout << "YES" << endl;
            continue;
        }
        vector<int> n[6];

        // y
        for (int i = 0; i < 6; i++) {
            n[i].clear();
            for (int j = 0; j < 4; j++) {
                n[i].push_back(m[i][j]);
            }
        }
        for (int i = 0; i < 3; i++) {
            n[i][1] = m[i + 1][1], n[i][3] = m[i + 1][3];
        }
        n[3][1] = m[0][1], n[3][3] = m[0][3];
        if (judge(n)) {
            cout << "YES" << endl;
            continue;
        }
        for (int i = 0; i < 6; i++) {
            n[i].clear();
            for (int j = 0; j < 4; j++) {
                n[i].push_back(m[i][j]);
            }
        }
        for (int i = 1; i < 4; i++) {
            n[i][1] = m[i - 1][1], n[i][3] = m[i - 1][3];
        }
        n[0][1] = m[3][1], n[0][3] = m[3][3];
        if (judge(n)) {
            cout << "YES" << endl;
            continue;
        }

        // x
        vector<int> mm[6];
        for (int i = 0; i < 4; i++) {
            mm[0].push_back(m[0][i]);
            mm[1].push_back(m[5][i]);
            // mm[2].push_back(m[2][i]);
            mm[3].push_back(m[4][i]);
            mm[4].push_back(m[1][i]);
            mm[5].push_back(m[3][i]);
        }
        mm[2].push_back(m[2][2]);
        mm[2].push_back(m[2][3]);
        mm[2].push_back(m[2][0]);
        mm[2].push_back(m[2][1]);
        for (int i = 0; i < 6; i++) {
            n[i].clear();
            for (int j = 0; j < 4; j++) {
                n[i].push_back(mm[i][j]);
            }
        }
        for (int i = 0; i < 3; i++) {
            n[i][2] = mm[i + 1][2], n[i][3] = mm[i + 1][3];
        }
        n[3][2] = mm[0][2], n[3][3] = mm[0][3];

        if (judge(n)) {
            cout << "YES" << endl;
            continue;
        }
        for (int i = 0; i < 6; i++) {
            n[i].clear();
            for (int j = 0; j < 4; j++) {
                n[i].push_back(mm[i][j]);
            }
        }
        for (int i = 1; i < 4; i++) {
            n[i][2] = mm[i - 1][2], n[i][3] = mm[i - 1][3];
        }
        n[0][2] = mm[3][2], n[0][3] = mm[3][3];

        if (judge(n)) {
            cout << "YES" << endl;
            continue;
        }

        // z
        for (int i = 0; i < 6; i++) {
            n[i].clear();
            for (int j = 0; j < 4; j++) {
                n[i].push_back(m[i][j]);
            }
        }
        n[4][1] = m[1][0], n[4][3] = m[1][1];
        n[1][0] = m[5][2], n[1][1] = m[5][0];
        n[5][2] = m[3][3], n[5][0] = m[3][2];
        n[3][3] = m[4][1], n[3][2] = m[4][3];
        if (judge(n)) {
            cout << "YES" << endl;
            continue;
        }
        for (int i = 0; i < 6; i++) {
            n[i].clear();
            for (int j = 0; j < 4; j++) {
                n[i].push_back(m[i][j]);
            }
        }

        n[1][0] = m[4][1], n[1][1] = m[4][3];
        n[5][2] = m[1][0], n[5][0] = m[1][1];
        n[3][3] = m[5][2], n[3][2] = m[5][0];
        n[4][1] = m[3][3], n[4][3] = m[3][2];
        if (judge(n)) {
            cout << "YES" << endl;
            continue;
        }
        // final
        cout << "NO" << endl;
    }
    return 0;
}