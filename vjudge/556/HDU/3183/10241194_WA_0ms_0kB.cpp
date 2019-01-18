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
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int maxn = 4000;
bool vis[maxn];
pii a[maxn];
int main() {
    ios::sync_with_stdio(false);
    string str;
    int m;
    while (cin >> str >> m) {
        if (m == str.size()) {
            cout << 0 << endl;
            continue;
        }
        REP(i, 0, str.size()) {
            a[i].first = str[i] - '0';
            a[i].second = -i;
        }
        sort(a, a + str.size());
        mems(vis, false);
        PER(i, str.size() - m, str.size()) {
            vis[-a[i].second] = true;
        }
        bool flag = false;
        REP(i, 0, str.size()) {
            if (!vis[i]) {
                if (str[i] != '0') {
                    cout << str[i];
                    flag = true;
                } else if (flag)
                    cout << str[i];
            }
        }
        if (!flag) cout << 0;
        cout << endl;
    }
}