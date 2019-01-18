#include <bits/stdc++.h>
#define endl "\n"
#define REP(i, x, n) for (int i = (x); i < (n); i++)
#define PER(i, x, n) for (int i = (n); i >= (x); i--)
#define sqr(x) ((x) * (x))
#define pii pair<char, int>
#define PI acos(-1.0)
#define MOD 1000000007
#define eps 1e-5
#define EPS 1e-6
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
            continue;
        }
        a = double(B * B) / double(4 * A);
        d = B * B + 4 * a * (a - y);
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
                double l = x - PI, r = x;
                double mid = (l + r) / 2;
                bool flag = true;
                while (r - l > eps) {
                    if (ff(mid) - gg(mid) > EPS && ff(mid) - gg(mid) < eps) {
                        printf("%.5f\n", mid);
                        flag = false;
                        break;
                    }
                    if (ff(mid) - gg(mid) < EPS) {
                        l = mid;
                    } else {
                        if (ff(mid) - gg(mid) > eps) {
                            r = mid;
                        } else {
                            l = mid;
                        }
                    }
                }
                if (!flag) {
                    printf("%.5f\n", (r + l) / 2);
                }

            } else {
                double l = 0, r = PI / 2;
                double mid = (l + r) / 2;
                bool flag = true;
                while (r - l > eps) {
                    mid = (l + r) / 2;
                    if (ff(mid) - gg(mid) > EPS && ff(mid) - gg(mid) < eps) {
                        printf("%.5f\n", mid);
                        flag = false;
                        break;
                    }
                    if (ff(mid) - gg(mid) < EPS) {
                        l = mid;
                    } else {
                        if (ff(mid) - gg(mid) > eps) {
                            r = mid;
                        } else {
                            l = mid;
                        }
                    }
                }
                if (!flag) {
                    printf("%.5f\n", (l + r) / 2);
                }
            }
        }
    }
    return 0;
