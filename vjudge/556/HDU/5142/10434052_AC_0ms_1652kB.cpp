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
#define REP(i, a, n) for (int i = a; i < (n); ++i)
#define PER(i, a, n) for (int i = (n) -1; i >= a; --i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int mid = 3000;
const int maxn = 2010;
inline int readT() {
    char c;
    int ret = 0, flag = 0;
    while (c = getchar(), (c < '0' || c > '9') && c != '-')
        ;
    if (c == '-')
        flag = 1;
    else
        ret = c ^ 48;
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c ^ 48);
    return flag ? -ret : ret;
}

int main() {
    int t, m, n;
    t = readT();
    while (t--) {
        n = readT();
        int ans = 0;
        int a[33], cnt = 0;
        while (n) {
            a[cnt++] = n & 1;
            n >>= 1;
        }
        REP(i, 0, cnt) {
            ans <<= 1;
            ans |= a[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}