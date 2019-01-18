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
#define ll long long
#define endl "\n"
#define DE cout << "------" << endl
#define mems(a, b) memset(a, b, sizeof a)
#define pii pair<int, int>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
// Shift_and 匹配字符串

int n;
bitset<1005> bst_b[128]; //按照题目要求更换，模式串字符数
// s为目标串 p为模式串
inline int shift_and(char *s, int len_s, /* char *p,*/ int len_p) { //如果速度慢可以直接写到主函数中
    bitset<1005> bst_d;

    for (int i = 0; i < len_s; i++) {
        bst_d = bst_d << 1;
        bst_d.set(0);                      //将第一位设置为1
        bst_d = bst_d & bst_b[s[i] - '0']; //与运算判断它是否是后缀
        if (bst_d[n - 1] == 1) {
            // 输出字符串
            char tmp = s[i + 1];
            s[i + 1] = '\0';
            cout << s + i + 1 - len_p << endl;
            s[i + 1] = tmp;
            // return s + i - n + 1; //返回找到的字符串首地址，若有多个可以储存到vector中
        }
    }
    return 0;
}
char sstr[5005000];
int main() {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        for (int i = 0; i < 12; i++) {
            bst_b[i].reset();
        }
        // memset(B, 0, (B));
        for (int i = 0; i < n; i++) {
            int nn;
            cin >> nn;
            for (int j = 0; j < nn; j++) {
                char c;
                cin >> c;
                bst_b[c - '0'].set(i);
            }
        }
        cin >> sstr;
        shift_and(sstr, strlen(sstr), n);
    }
    return 0;
}