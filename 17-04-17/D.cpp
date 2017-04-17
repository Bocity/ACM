#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10, pi = acos(-1.0);
inline int dcmp(double x) {
    return (x > eps) - (x < -eps);
}

struct Point {
    double x, y;
    Point(double x = 0, double y = 0)
        : x(x)
        , y(y) {}
    void input() {
        scanf("%lf%lf", &x, &y);
    }
    bool operator<(const Point &R) const {
        if (dcmp(x - R.x) == 0) return dcmp(y - R.y) < 0;
        return dcmp(x - R.x) < 0;
    }
    bool operator==(const Point &R) const {
        return dcmp(x - R.x) == 0 && dcmp(y - R.y) == 0;
    }
    Point operator+(const Point &R) const {
        return Point(x + R.x, y + R.y);
    }
    Point operator-(const Point &R) const {
        return Point(x - R.x, y - R.y);
    }
    Point operator*(const double &R) const {
        return Point(x * R, y * R);
    }
    Point operator/(const double &R) const {
        return Point(x / R, y / R);
    }
    double operator^(const Point &R) const {
        return x * R.y - y * R.x;
    }
    double operator%(const Point &R) const {
        return x * R.x + y * R.y;
    }
    double len() {
        return sqrt(*this % *this);
    }
};
double DistancePointToLine(Point P, Point A, Point B) {
    if (A == B) return (P - A).len();
    Point v1 = B - A, v2 = P - A, v3 = P - B;
    if (dcmp(v1 % v2) < 0) return v2.len();
    if (dcmp(v1 % v3) > 0) return v3.len();
    return fabs(v1 ^ v2) / v1.len();
}
long long a[1010], b[1010];
double check(int i, int j, int k) {
    return DistancePointToLine(Point(a[k], b[k]), Point(a[i], b[i]), Point(a[j], b[j]));
}
int main() {
    ios::sync_with_stdio(false);
#ifdef ST
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        double ans = 1e20;
        for (int i = 0; i < n; i++) {
            double temp = check(i, (i + 2) % n, (i + 1) % n);
            if (temp < ans) ans = temp;
        }
        printf("%.7lf\n", ans / 2);
    }
}