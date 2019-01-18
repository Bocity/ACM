#include <bits/stdc++.h>
#define REP(i, x, n) for (long long i = (x); i < (n); i++)
#define PER(i, x, n) for (long long i = (n); i >= (x); i--)
#define endl "\n"
#define mems(a, x) memset(a, (x), sizeof a)
using namespace std;
typedef long long ll;
const int maxn = 10000;
typedef bitset<905> Bitset;
Bitset a[905][4], b[905][4];
int n;
int x;
int fuck(int x, int y) {
    int ppstay = 0;
    ppstay += (a[x][1] & b[y][1]).count();
    ppstay += 2 * (a[x][1] & b[y][2]).count();
    ppstay += 2 * (a[x][2] & b[y][1]).count();
    ppstay += (a[x][2] & b[y][2]).count();
    return ppstay;
}
void stay() {
    REP(j, 0, 801) {
        REP(i, 0, 3) {
            a[j][i].reset();
        }
    }
    REP(i, 0, n) {
        REP(j, 0, n) {
            cin >> x;
            x %= 3;
            a[i][x].set(j);
        }
    }
    REP(i, 0, n) {
        REP(j, 0, n) {
            cin >> x;
            x %= 3;
            b[j][x].set(i);
        }
    }
    REP(i, 0, n) {
        REP(j, 0, n - 1) {
            cout << fuck(i, j) % 3 << " ";
        }
        cout << fuck(i, n - 1) % 3 << endl;
    }
}
int main() {
    ios::sync_with_stdio(0);
    while (cin >> n) {
        stay();
    }
    return 0;
}