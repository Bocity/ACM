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
const int maxn = 600000;
vector<int> v[maxn];
vector<pii> fuck[maxn];
vector<int> cnt[maxn];
vector<int> peo;
vector<vector<int>> ans_peo;
bool vis[maxn];
void print(vector<int> temp) {
    cout << temp.size();
    while (temp.size()) {
        cout << " " << temp.back();
        temp.pop_back();
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    int n, m, p, num, temp;
    cin >> n >> m >> p;
    REP(i, 1, n + 1) {
        fuck[i].clear();
    }
    REP(i, 1, m + 1) {
        cin >> num;
        v[i].clear();
        REP(j, 0, num) {
            cin >> temp;
            v[i].push_back(temp);
            fuck[temp].push_back(pii(num, i));
        }
    }
    REP(i, 1, n + 1) {
        sort(all(fuck[i]));
    }
    REP(i, 1, m + 1) {
        cnt[i].clear();
    }
    REP(i, 1, p + 1) {
        cin >> temp;
        cnt[temp].push_back(i);
    }
    int ans = 0;
    ans_peo.clear();
    while (1) {
        mems(vis, false);
        peo.clear();
        REP(i, 1, n + 1) {
            if (!vis[i]) {
                for (auto j : fuck[i]) {
                    if (cnt[j.second].size()) {
                        for (auto z : v[j.second]) {
                            vis[z] = true;
                        }
                        peo.push_back(cnt[j.second].back());
                        cnt[j.second].pop_back();
                        break;
                    }
                }
                if (!vis[i]) {
                    goto exit;
                }
            }
        }
        ans++;
        ans_peo.push_back(peo);
    }
exit:
    cout << ans << endl;
    while (ans_peo.size()) {
        print(ans_peo.back());
        ans_peo.pop_back();
    }
    return 0;
}