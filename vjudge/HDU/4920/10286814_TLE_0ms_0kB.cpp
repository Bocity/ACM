#include <bits/stdc++.h>
#define REP(i, x, n) for (long long i = (x); i < (n); i++)
#define PER(i, x, n) for (long long i = (n); i >= (x); i--)
#define endl "\n"
#define mems(a, x) memset(a, (x), sizeof a)
using namespace std;
typedef long long ll;
const int maxn = 10000;
typedef bitset<10005> Bitset;
const int N = 802;
struct Mat {
    ll mat[N][N]; //每个Mat使用前都要memset 。  否则会出现奇奇怪怪的错误
};
Mat a, b, c;
int n;
void cheng() {
    int i, j, k;
    for (k = 0; k < n; ++k) {
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % 3;
            }
        }
    }
    return;
}

void stay() {
    mems(a.mat, 0);
    mems(b.mat, 0);
    // cout << " - ";
    REP(i, 0, n) {
        REP(j, 0, n) {
            cin >> a.mat[i][j];
        }
    }
    REP(i, 0, n) {
        REP(j, 0, n) {
            cin >> b.mat[i][j];
        }
    }
    cheng();
    REP(i, 0, n) {
        REP(j, 0, n - 1) {
            cout << c.mat[i][j] << " ";
        }
        cout << c.mat[i][n - 1] << endl;
    }
}
int main() {
    ios::sync_with_stdio(0);
    while (cin >> n) {
        stay();
    }
    return 0;
}