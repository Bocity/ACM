#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#define all(a) (a).begin(), (a).end()
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define REP(i, a, n) for (int i = a; i < (n); i++)
#define PER(i, a, n) for (int i = (n) -1; i >= a; i--)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int mp[50][50];
bool vis[50][50];
int _x[] = {0, 1};
int _y[] = {1, 0};
vector<int> v;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    int ccnt = 1;
    cin >> t;
    int n, m;
    while (t--) {
        cin >> n >> m;
        REP(i, 0, n) {
            REP(j, 0, m) {
                cin >> mp[i][j];
            }
        }
        bool fg = false;
        int x, y;
        REP(i, 0, n) {
            if (fg) break;
            REP(j, 0, m) {
                if (fg) break;
                REP(k, 0, 2) {
                    x = _x[k] + i;
                    y = _y[k] + j;
                    if (x >= 0 && x < n && y >= 0 && y < m) {
                        if (mp[i][j] == mp[x][y]) {
                            fg = true;
                            break;
                        }
                    }
                }
            }
        }
        v.clear();
        REP(i, 0, n) {
            v.push_back(mp[i][0]);
        }
        sort(all(v), greater<int>());
        REP(i, 1, v.size()) {
            if (v[i] == v[i - 1]) {
                fg = true;
                break;
            }
        }
        v.clear();
        REP(i, 0, n) {
            v.push_back(mp[i][m - 1]);
        }
        sort(all(v), greater<int>());
        REP(i, 1, v.size()) {
            if (v[i] == v[i - 1]) {
                fg = true;
                break;
            }
        }
        v.clear();
        REP(i, 0, m) {
            v.push_back(mp[n - 1][i]);
        }
        sort(all(v), greater<int>());
        REP(i, 1, v.size()) {
            if (v[i] == v[i - 1]) {
                fg = true;
                break;
            }
        }
        v.clear();
        REP(i, 0, n) {
            v.push_back(mp[0][i]);
        }
        sort(all(v), greater<int>());
        REP(i, 1, v.size()) {
            if (v[i] == v[i - 1]) {
                fg = true;
                break;
            }
        }
        cout << "Case #" << ccnt++ << ": ";
        cout << (fg ? "Yes" : "No") << endl;
    }
}