#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
typedef long long int64;
ll n, k, MOD, f[100];
const int N = 10;
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
Mat operator^(Mat a, int k) {
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

int main() {
    ios::sync_with_stdio(false);
    while (cin >> n >> k) {
        MOD = k;
        Mat a1, a2, a3;
        memset(a1.mat, 0, sizeof a1.mat);
        memset(a2.mat, 0, sizeof a2.mat);
        memset(a3.mat, 0, sizeof a3.mat);
        for (int i = 0; i < 10; i++) {
            cin >> a1.mat[0][i];
        }
        if (n < 10) {
            cout << n % k << endl;
            continue;
        }
        for (int i = 0; i < 9; i++) {
            a1.mat[i + 1][i] = 1;
        }
        for (int i = 0; i < 10; i++) {
            a2.mat[i][0] = 9 - i;
        }
        a3 = a1 ^ (n - 9);
        a3 = a3 * a2;
        cout << a3.mat[0][0] << endl;
    }

    return 0;
}