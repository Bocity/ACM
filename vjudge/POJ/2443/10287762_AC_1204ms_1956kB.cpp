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
#define REP(i, x, n) for (long long i = (x); i < (n); i++)
#define PER(i, x, n) for (long long i = (n); i >= (x); i--)
#define endl "\n"
#define mems(a, x) memset(a, (x), sizeof a)
using namespace std;
typedef long long ll;
const int maxn = 10000;
typedef bitset<1005> Bitset;
Bitset q[10015];
bool vis[20005];
int n, m, y, t;
int x;
int read() {
    int n = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0') {
        if (ch == '-') {
            f = -1;
        }
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0') {
        n = n * 10 + ch - '0';
        ch = getchar();
    }
    return n * f;
}
void stay(int n) {
    // mems(vis, 0);
    REP(i, 0, 10005) {
        q[i].reset();
    }
    REP(i, 0, n) {
        m = read();
        REP(j, 0, m) {
            x = read();
            q[x].set(i);
        }
    }
    t = read();
    while (t--) {
        x = read();
        y = read();
        printf(((q[x] & q[y]).any()) ? "Yes" : "No");
        puts("");
    }
}
int main() {
    // ios::sync_with_stdio(0);
    while (scanf("%d", &n) != EOF) {
        stay(n);
    }
    return 0;
}