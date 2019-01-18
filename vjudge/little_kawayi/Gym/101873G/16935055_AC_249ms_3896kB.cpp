#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Point {
    double x, y;
    Point(const double &x = 0, const double &y = 0) :x(x), y(y) {}
    friend Point operator+(const Point &a, const Point &b) {
        return Point(a.x + b.x, a.y + b.y);
    }
    friend Point operator-(const Point &a, const Point &b) {
        return Point(a.x - b.x, a.y - b.y);
    }
    friend Point operator*(const double &c, const Point &a) {
        return Point(c * a.x, c * a.y);
    }
    friend Point operator*(const Point &a, const double &c) {
        return Point(c * a.x, c * a.y);
    }
    friend double det(const Point &a, const Point &b) {
        return a.x * b.y - a.y * b.x;
    }
};
struct Polygon {
//#define Next(i) ((i + 1）% n)
    int n;
    vector<Point> p;
    Polygon(vector<Point> &v) : p(v) {n = p.size();}
    double area() {
        double sum = 0;
        for(int i = 0; i < n; i++) {
            sum += det(p[i], p[(i + 1) % n]);
        }
        return fabs(sum) / 2;
    }
    ll borderPoint() {
        ll num = 0;
        for(int i = 0; i < n; i++) {
            num += __gcd((ll)fabs(
                                  p[(i + 1) % n].x
                                   - p[i].x), (ll)fabs(p[(i + 1) % n].y - p[i].y));
        }
        return num;
    }
    ll insidePoint() {
        return (ll)(area()) + 1 - borderPoint() / 2;
    }
};
int main() {
    int n, xx, yy;
    vector<Point> v;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> xx >> yy;
        v.push_back(Point(xx, yy));
    }
    Polygon pp(v);
    cout << pp.insidePoint() << endl;
}
