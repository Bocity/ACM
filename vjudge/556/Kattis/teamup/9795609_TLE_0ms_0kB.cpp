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
set<pii, greater<pii>> fuck[maxn];
vector<int> cnt[maxn];
vector<int> peo;
vector<vector<int>> ans_peo;
bool vis[maxn];
inline void print(vector<int> &temp) {
    printf("%d", temp.size());
    while (temp.size()) {
        printf(" %d", temp.back());
        temp.pop_back();
    }
    puts("");
}
inline int readT() {
    char c;
    int ret = 0, flag = 0;
    while (c = getchar(), (c < '0' || c > '9') && c != '-')
        ;
    if (c == '-')
        flag = 1;
    else
        ret = c ^ 48;
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c ^ 48);
    return flag ? -ret : ret;
}
int main() {
    int n, m, p, num, temp;
    n = readT();
    m = readT();
    p = readT();
    REP(i, 1, n + 1) {
        fuck[i].clear();
    }
    REP(i, 1, m + 1) {
        num = readT();
        v[i].clear();
        REP(j, 0, num) {
            temp = readT();
            v[i].push_back(temp);
        }
        sort(all(v[i]));
        fuck[v[i][0]].insert(pii(num, i));
    }
    REP(i, 1, m + 1) {
        cnt[i].clear();
    }
    REP(i, 1, p + 1) {
        temp = readT();
        cnt[temp].push_back(i);
    }
    int ans = 0;
    ans_peo.clear();
    while (1) {
        mems(vis, false);
        ans_peo.push_back(vector<int>());
        REP(i, 1, n + 1) {
            if (!vis[i]) {
                for (auto &j : fuck[i]) {
                    if (cnt[j.second].size()) {
                        for (auto &z : v[j.second]) {
                            vis[z] = true;
                        }
                        ans_peo[ans].push_back(cnt[j.second].back());
                        cnt[j.second].pop_back();
                        if (!cnt[j.second].size()) fuck[i].erase(j);
                        break;
                    }
                }
                if (!vis[i]) {
                    goto exit;
                }
            }
        }
        ans++;
    }
exit:
    printf("%d\n", ans);
    REP(i, 0, ans) {
        print(ans_peo[i]);
    }
    return 0;
}