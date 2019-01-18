#include <bits/stdc++.h>
#define endl "\n"
#define REP(i, x, n) for (int i = (x); i < (n); i++)
#define PER(i, x, n) for (int i = (n); i >= (x); i--)
#define sqr(x) ((x) * (x))
#define pii pair<char, int>
#define PI acos(-1.0)
typedef long long ll;
using namespace std;
const int N = 3;
struct Mat {
    double mat[N][N]; //每个Mat使用前都要memset 。  否则会出现奇奇怪怪的错误
};
Mat operator*(Mat a, Mat b) {
    Mat c;
    memset(c.mat, 0, sizeof(c.mat));
    int i, j, k;
    for (k = 0; k < N; ++k) {
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]);
            }
        }
    }
    return c;
}
ll n, T, t;
double a, b, p;
double c, s, x1, y11, ansx, ansy;
Mat ans1, ans2, r;
int main() {
    cin >> T;
    while (T--) {
        memset(ans1.mat, 0, sizeof ans1.mat);
        memset(ans2.mat, 0, sizeof ans2.mat);
        memset(r.mat, 0, sizeof r.mat);
        ans1.mat[0][0] = 1;
        ans2.mat[0][0] = 2;
        ans1.mat[1][0] = 1;
        ans2.mat[1][0] = 1;
        ans1.mat[2][0] = 1;
        ans2.mat[2][0] = 1;
        cin >> n;
        REP(i, 0, n) {
            cin >> a >> b >> p;
            c = cos(p);
            s = sin(p);
            r.mat[0][0] = c, r.mat[0][1] = -s, r.mat[0][2] = (1.0 - c) * a + s * b;
            r.mat[1][0] = s, r.mat[1][1] = c, r.mat[1][2] = (1.0 - c) * b - s * a;
            r.mat[2][0] = 0, r.mat[2][1] = 0, r.mat[2][2] = 1;
            ans1 = r * ans1;
            ans2 = r * ans2;
        }
        x1 = ans1.mat[0][0];
        y11 = ans1.mat[1][0];
        double jj = acos(ans2.mat[0][0] - ans1.mat[0][0]);
        if (ans2.mat[0][0] - ans1.mat[0][0] < 0) jj = PI * 2 - acos(ans2.mat[0][0] - ans1.mat[0][0]);
        s = sin(jj);
        c = ans2.mat[0][0] - ans1.mat[0][0];
        // cout << x1 << " " << y11 << " " << acos(ans2.mat[0][0] - ans1.mat[0][0]) << "---" << endl;
        if (s == 0 && c == 1) {
            ansx = a;
            ansy = b;

        } else {
            ansx = (x1 * (1 - c) - s * y11 - c * (1 - c) + s * (1 - c) + s * s + c * s) / ((1 - c) * (1 - c) + s * s);
            ansy = (s * x1 + (1 - c) * y11 + s * s - c * s - s * (1 - c) - c * (1 - c)) / ((1 - c) * (1 - c) + s * s);
        }
        if (ans2.mat[0][0] - ans1.mat[0][0] < 0)
            printf("%.10f %.10f %.10f\n", ansx, ansy, PI * 2 - acos(ans2.mat[0][0] - ans1.mat[0][0]));
        else
            printf("%.10f %.10f %.10f\n", ansx, ansy, acos(ans2.mat[0][0] - ans1.mat[0][0]));
    }
    return 0;
}