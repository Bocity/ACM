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
const int maxn = 2050;
// bitset<maxn> bst_b[28];
// bitset<maxn> bst_d;
// int shift_and(string s, string p) { //如果速度慢可以直接写到主函数中
//     int len_s = s.size();
//     int len_p = p.size();
//     for (int i = 0; i < 28; i++) {
//         bst_b[i].reset();
//     }
//     bst_d.reset();
//     for (int i = 0; i < len_p; i++) {
//         bst_b[p[i] - 'a'].set(i);
//     }
//     for (int i = 0; i < len_s; i++) {
//         bst_d = bst_d << 1;
//         bst_d.set(0);                      //将第一位设置为1
//         bst_d = bst_d & bst_b[s[i] - 'a']; //与运算判断它是否是后缀
//         if (bst_d[len_p - 1] == 1) {
//             return 1;
//         }
//     }
//     return 0;
// }
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
        int ans = 0, pre = 0;
        PER(i, 1, n) {
            if (str[i].find(str[i - 1]) == string::npos) {
                PER(j, i, n) {
                    REP(k, 0, i) {
                        if (str[j].find(str[k]) == string::npos) {
                            ans = j;
                            goto exit;
                        }
                    }
                }
            }
        }
    exit:
        cout << "Case #" << cas << ": ";
        if (ans == 0)
            cout << "-1" << endl;
        else {
            cout << ans + 1 << endl;
        }
    }
    return 0;
}