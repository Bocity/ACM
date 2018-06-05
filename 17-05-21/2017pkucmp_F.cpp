#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 3;
ll MOD;
struct Mat {
    ll mat[N][N];
};
Mat operator*(Mat a, Mat b) {
    Mat c;
    memset(c.mat, 0, sizeof(c.mat));
    int i, j, k;
    for (k = 0; k < N; ++k) {
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % MOD;
            }
        }
    }
    return c;
}
Mat operator^(Mat a, ll k) {
    Mat c;
    int i, j;
    for (i = 0; i < N; ++i)
        for (j = 0; j < N; ++j) c.mat[i][j] = (i == j);

    for (; k; k >>= 1) {
        if (k & 1) c = c * a;
        a = a * a;
    }
    return c;
}
ll T, n;
int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    Mat a1, a2, a3;
    memset(a1.mat, 0, sizeof a1.mat);
    memset(a2.mat, 0, sizeof a2.mat);
    memset(a3.mat, 0, sizeof a3.mat);
    while (T--) {
        cin >> n;
        if (n == 0) {
            cout << 1 << "\n";
            continue;
        }
        MOD = 1e9 + 7;
        a1.mat[0][0] = 7;
        a1.mat[0][1] = 12;
        a1.mat[1][0] = 4;
        a1.mat[1][1] = 7;
        a2.mat[0][0] = 7;
        a2.mat[1][0] = 4;
        a3 = (a1 ^ (n - 1)) * a2;
        cout << ((a3.mat[0][0] * 2) - 1) % MOD << "\n";
    }
    return 0;
}
