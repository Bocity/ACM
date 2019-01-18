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
typedef pair<ll, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 100;
ll ans = 0;
int n, k;
vector<pii> edge[MAXN];
pii dis[MAXN];
int cnt[MAXN];
void dfs(int pos, int fa) {
    cnt[pos]++;
    for (auto to : edge[pos]) {
        if (to.second != fa) {
            dis[to.second].first = to.first;
            dfs(to.second, pos);
            cnt[pos] += cnt[to.second];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> k) {
        ll sum = 0;
        int a, b, c;
        mems(cnt, 0);
        REP(i, 0, n + 1) {
            edge[i].clear();
            dis[i].second = i;
        }
        REP(i, 0, n - 1) {
            cin >> a >> b >> c;
            edge[a].push_back(pii(c, b));
        }
        dis[1].first = 0;
        dfs(1, -1);
        REP(i, 2, n + 1) {
            sum += dis[i].first * min(cnt[i], k);
        }
        cout << sum << endl;
    }
    return 0;
}