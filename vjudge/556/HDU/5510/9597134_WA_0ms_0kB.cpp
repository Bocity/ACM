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
// bitset<2005> bst_b[26]; //按照题目要求更换，模式串字符数
// // s为目标串 p为模式串
// int shift_and(char s[], char p[]) { //如果速度慢可以直接写到主函数中
//     int len_s = strlen(s);
//     int len_p = strlen(p);
//     bitset<2005> bst_d;
//     for (int i = 0; i < 26; i++) bst_b[i].reset();
//     for (int i = 0; i < len_p; i++) {
//         bst_b[p[i]].set(i);
//     }
//     for (int i = 0; i < len_s; i++) {
//         bst_d = bst_d << 1;
//         bst_d.set(0);                      //将第一位设置为1
//         bst_d = bst_d & bst_b[s[i] - '0']; //与运算判断它是否是后缀
//         if (bst_d[len_p - 1] == 1) {
//             // 输出字符串
//             // char tmp = s[i + 1];
//             // s[i + 1] = '\0';
//             // cout << s + i + 1 - len_p << endl;
//             // s[i + 1] = tmp;
//             return 1; //返回找到的字符串首地址，若有多个可以储存到vector中
//         }
//     }
//     return -1;
// }
string str[510];
bool vis[510];
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
            if (str[i].find(str[i - 1]) == string::npos) {
                if (i == n - 1) {
                    ans = n - 1;
                    break;
                }
                PER(j, i, n) {
                    if (str[j].find(str[i - 1]) == string::npos) {
                        ans = j;
                        break;
                    }
                }
                break;
            }
        }
        cout << "Case #" << cas << ": ";
        if (ans == 0)
            cout << -1 << endl;
        else
            cout << ans + 1 << endl;
    }
    return 0;
}