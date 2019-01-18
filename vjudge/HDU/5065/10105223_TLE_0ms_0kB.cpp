#include <bits/stdc++.h>
#define endl "\n"
#define REP(i, x, n) for (int i = (x); i < (n); i++)
#define PER(i, x, n) for (int i = (n); i >= (x); i--)
#define sqr(x) ((x) * (x))
#define pii pair<char, int>
#define PI acos(-1.0)
#define MOD 1000000007
#define eps 1e-6
#define EPS 1e-9
typedef long long ll;
using namespace std;
ll k, n, T, m, ans, A, B, y;
double a, b, x1, x2, d;
inline double ff(double x) {
    return A * 1.0 * x * x - y;
}
inline double gg(double x) {
    return B * 1.0 * sin(x);
}
int main() {
    cin >> T;
    while (T--) {
        cin >> A >> B;
        cin >> y;
        if (B == 0) {
            if (A == 0 && y != 0) {
                cout << "error" << endl;
                continue;
            }
            if (y < 0) {
                cout << "error" << endl;
                continue;
            }
            printf("%.5f\n", sqrt(y * 1.0 / A));
        }
        a = double(B * B) / double(4 * A);
        d = B * B + 4 * a * (a - y);
        cout << d;
        if (d < 0) {
            cout << "error" << endl;
        } else {
            x1 = (double(B - sqrt(d))) / (-2.0 * a);
            x2 = (double(B + sqrt(d))) / (-2.0 * a);
            if (fabs(x1) > 1 || fabs(x2) > 1) {
                cout << "error" << endl;
                continue;
            }
            if (ff(0) <= 0) {
                double x;
                x = PI / 2;
                while (ff(x) - gg(x) < 0) {
                    x += PI;
                }
                for (double i = x; i >= x - PI / 2; i -= 0.00001) {
                    if ((ff(i) - gg(i)) < eps) {
                        printf("%.5f\n", i);
                        break;
                    }
                }
            } else {
                for (double i = 0; i < PI / 2; i += 0.00001) {
                    if ((ff(i) - gg(i)) > eps) {
                        printf("%.5f\n", i);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}