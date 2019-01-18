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
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
ll a[100] = {1,         199981,    199982,    199983,    199984,    199985,    199986,    199987,    199988,
             199989,    199990,    200000,    200001,    1599981,   1599982,   1599983,   1599984,   1599985,
             1599986,   1599987,   1599988,   1599989,   1599990,   2600000,   2600001,   13199998,  35000000,
             35000001,  35199981,  35199982,  35199983,  35199984,  35199985,  35199986,  35199987,  35199988,
             35199989,  35199990,  35200000,  35200001,  117463825, 500000000, 500000001, 500199981, 500199982,
             500199983, 500199984, 500199985, 500199986, 500199987, 500199988, 500199989, 500199990, 500200000,
             500200001, 501599981, 501599982, 501599983, 501599984, 501599985, 501599986, 501599987, 501599988,
             501599989, 501599990, 502600000, 502600001, 513199998, 535000000, 535000001, 535199981, 535199982,
             535199983, 535199984, 535199985, 535199986, 535199987, 535199988, 535199989, 535199990, 535200000,
             535200001, 1111111110};
ll convert(string s) {
    ll ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans *= 10;
        ans += s[i] - '0';
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    string x;
    ll n;
    while (cin >> x) {
        if (x.size() > 10) {
            cout << "83 1111111110" << endl;
        } else {
            n = convert(x);
            if (n >= 1111111110) {
                cout << "83 1111111110" << endl;
                continue;
            }
            int pos = upper_bound(a, a + 84, n) - a;
            cout << pos << " " << a[pos - 1] << endl;
        }
    }
    return 0;
}