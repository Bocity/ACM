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
int a[101000];
bool vis[101000];
vector<int> ans;
int main() {
    ios::sync_with_stdio(false);
    ll n;
    while (cin >> n) {
        mems(vis, false);
        REP(i, 1, n + 1) {
            cin >> a[i];
        }
        int temp;
        REP(i, 1, n + 1) {
            if (!vis[i]) {
                ans.clear();
                temp = i;
                while (!vis[temp]) {
                    ans.push_back(temp);
                    vis[temp] = true;
                    temp = a[temp];
                }
                REP(j, 0, ans.size()) cout << " ("[j == 0] << ans[j];
                cout << ")";
            }
        }
        cout << endl;
    }
    return 0;
}