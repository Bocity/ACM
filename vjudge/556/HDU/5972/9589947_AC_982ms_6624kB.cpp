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
bitset<1005> B[12];
char sstr[5005000];
int n;
inline int shift_and(char *s, int len_s, int len_p) {
    bitset<1005> D;
    for (int i = 0; i < len_s; i++) {
        D = D << 1;
        D.set(0);
        D = D & B[s[i] - '0'];
        if (D[n - 1] == 1) {
            char tmp = s[i + 1];
            s[i + 1] = '\0';
            cout << s + i + 1 - n << endl;
            s[i + 1] = tmp;
            // for (int j = i - len_p + 1; j < i - len_p + 1 + n; j++) {
            //     cout << s[j];
            // }
            // cout << endl;
        }
        // D = ((D << 1) | 1) & B[s[i] - '0']; // D<<1与1位或操作，是可以让匹配随时从当前字符开始，使用位运算实现了并行
        // if (D & (1 << (len_p - 1))) {
        //     for (int j = i - len_p + 1; j < i - len_p + 1 + n; j++) {
        //         cout << s[j];
        //     }
        //     cout << endl;
        // }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    while (cin >> n) {
        for (int i = 0; i < 12; i++) {
            B[i].reset();
        }
        // memset(B, 0, (B));
        for (int i = 0; i < n; i++) {
            int nn;
            cin >> nn;
            for (int j = 0; j < nn; j++) {
                char c;
                cin >> c;
                B[c - '0'].set(i);
            }
        }
        cin >> sstr;
        shift_and(sstr, strlen(sstr), n);
    }
    return 0;
}