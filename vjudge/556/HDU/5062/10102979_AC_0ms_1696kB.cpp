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
#include <sstream>
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

// bool check(string str) {
//     int sz = str.size();
//     int pre = str[0];
//     int szz = (sz & 1) ? (sz / 2 + 1) : (sz / 2);
//     REP(i, 1, szz) {
//         if (str[i] <= pre) return false;
//         pre = str[i];
//     }
//     REP(i, 0, sz) {
//         if (str[i] == '0') return false;
//     }
//     for (int i = 0, j = sz - 1; i < j; i++, j--) {
//         if (str[i] != str[j]) return false;
//     }
//     return true;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     int cnt = 0;
//     REP(i, 1, 1000001) {
//         ostringstream o;
//         o << i;
//         if (check(o.str())) cnt++;

//         if (i == 1) {
//             cout << cnt << endl;
//         }
//         if (i == 10) {
//             cout << cnt << endl;
//         }
//         if (i == 100) {
//             cout << cnt << endl;
//         }
//         if (i == 1000) {
//             cout << cnt << endl;
//         }
//         if (i == 10000) {
//             cout << cnt << endl;
//         }
//         if (i == 100000) {
//             cout << cnt << endl;
//         }
//         if (i == 1000000) {
//             cout << cnt << endl;
//         }
//     }
//     return 0;
// }
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 0) cout << 1 << endl;
        if (n == 1) cout << 9 << endl;
        if (n == 2) cout << 18 << endl;
        if (n == 3) cout << 54 << endl;
        if (n == 4) cout << 90 << endl;
        if (n == 5) cout << 174 << endl;
        if (n == 6) cout << 258 << endl;
    }
}