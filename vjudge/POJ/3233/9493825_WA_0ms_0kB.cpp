#include <algorithm>
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
using namespace std;
const int MOD = 10000;
const int INF = 0x3f3f3f3f;
const int N = 35;
int M;
struct Mat {
    ll mat[N][N]; //
};
Mat operator*(Mat a, Mat b) {
    Mat c;
    memset(c.mat, 0, sizeof(c.mat));
    int i, j, k;
    for (k = 0; k < N; ++k) {
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % M;
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
    int n, k, m;
    ios::sync_with_stdio(false);
    Mat b, c;
    memset(b.mat, 0, sizeof b.mat);
    memset(c.mat, 0, sizeof c.mat);
    cin >> n >> k >> m;
    M = m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b.mat[i][j];
        }
    }
    c = b ^ k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            cout << (((c.mat[i][j] % M + b.mat[i][j] % M) % M) * k / 2) % M << " ";
        }
        cout << (((c.mat[i][n - 1] % M + b.mat[i][n - 1] % M) % M) * k / 2) % M;
        cout << endl;
    }
    return 0;
}
