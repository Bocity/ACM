#include <algorithm>
#include <bitset>
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
string str[510];
int main() {
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    REP(cas, 1, t + 1) {
        cin >> n;
        REP(i, 0, n) {
            cin >> str[i];
        }
        int ans = 0;
        PER(i, 1, n) {
            if (str[i].find(str[i - 1]) == string::npos || str[i] == str[i - 1]) {
                PER(j, i, n) {
                    if (str[j].find(str[i - 1]) == string::npos || str[j] == str[i - 1]) {
                        ans = j;
                        break;
                    }
                }
                break;
            }
        }
        cout << "Case #" << cas << ": ";
        if (ans == 0)
            cout << "-1" << endl;
        else
            cout << ans + 1 << endl;
    }
    return 0;
}