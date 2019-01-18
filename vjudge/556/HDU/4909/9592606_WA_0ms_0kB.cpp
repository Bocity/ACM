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

using namespace std;
map<int, int> mp, mp2;
int main() {
    ios::sync_with_stdio(false);
    int t, pos, x, temp;
    ll ans;
    string str;
    cin >> t;
    while (t--) {
        cin >> str;
        pos = -1, x = 0;
        mp.clear();
        REP(i, 0, str.size()) {
            if (str[i] == '?') {
                pos = i;
            } else {
                str[i] -= 'a';
                x ^= 1 << str[i];
                mp[x]++;
            }
        }
        ans = 0;
        mp[0]++;
        for (auto i : mp) ans += i.second * (i.second - 1) / 2;

        if (~pos) {
            mp2.clear();
            x = 0;
            mp2[0] = 1;
            REP(i, 0, pos) {
                x ^= 1 << str[i];
                mp2[x]++;
            }
            mp.clear();
            mp[x]++;
            REP(i, pos + 1, str.size()) {
                x ^= 1 << str[i];
                mp[x]++;
            }
            REP(c, 0, 26) {
                for (auto i : mp) {
                    temp = i.first ^ (1 << c);
                    if (mp2.count(temp)) ans += i.second * mp2[temp];
                }
            }
            ans++;
        }
        cout << ans << endl;
    }
}