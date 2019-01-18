#include<bits/stdc++.h>
using namespace std;
const long double eps = 1e-10;
inline int dcmp(long double x)
{
    return (x > eps) - (x < -eps);
}
struct Point
{
    long double x, y;
    Point(long double x = 0, long double y = 0) : x(x), y(y) {}

    Point operator + (const Point &R)
    {
        return Point(x + R.x, y + R.y);
    }
    Point operator - (const Point &R)
    {
        return Point(x - R.x, y - R.y);
    }
    Point operator * (const long double &R)
    {
        return Point(x * R, y * R);
    }
    Point operator / (const long double &R)
    {
        return Point(x / R, y / R);
    }
};
int dis2(Point a, Point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
long double dot(Point a, Point b)
{
    return a.x * b.x + a.y * b.y;
}
struct Line
{
    Point P, V;
    long double angle;
    Line(Point A, Point B)
    {
        P = A, V = B - A;///y = A + P*t
        angle = atan2(V.y, V.x);
    }
    bool operator <(const Line &R) const
    {
        return angle < R.angle;
    }
    Point point(long double t)
    {
        return P + V * t;
    }
};
Point symPoint(Point p, Point s, Point t)
{
    return s * 2.0 - p + (t - s) * dot(p - s, t - s) * 2.0 / ((t.x - s.x) * (t.x - s.x) + (t.y - s.y) * (t.y - s.y));
}
struct Circle
{
    Point O;
    long double r;
    Circle() {}
    Circle(Point _O, long double _r)
    {
        O = _O, r = _r;
    }
    Point point (long double arc)
    {
        return Point(O.x + cos(arc) * r, O.y + sin(arc) * r);
    }
};
vector<Point> s;
int getX(Line L, Circle C, long double &t1, long double &t2)
{
    s.clear();
    long double a = L.V.x, b = L.P.x - C.O.x, c = L.V.y, d = L.P.y - C.O.y;
    long double e = a * a + c * c, f = 2 * (a * b + c * d);
    long double g = b * b + d * d - C.r * C.r;
    long double delta = f * f - 4 * e * g;
    if(dcmp(delta) < 0) return 0;
    if(dcmp(delta) == 0)
    {
        t1 = t2 = -f / (2 * e);
        s.push_back(L.point(t1));
    }
    t1 = (-f - sqrt(delta)) / (e + e);
    t2 = (-f + sqrt(delta)) / (e + e);
    s.push_back(L.point(t1));
    s.push_back(L.point(t2));
    return 2;
}
int main()
{
    int t;
    cin >> t;
    int cnt = 1;
    while(t--)
    {
        Circle c;
        Point a, b, v;
        cin >> c.O.x >> c.O.y >>c.r;
        cin >> a.x >> a.y >> v.x >> v.y >> b.x >> b.y;
        Line l(a, a + v);
        long double x1, x2;
        int tmp = getX(l, c, x1, x2);
        bool f = false;
        if(tmp == 0 || tmp == 1)
        {
            //cout << 1 << endl;
            if(v.x * (b.x - a.x) >= 0 && v.y * (b.y - a.y) >= 0) f = true;
        }
        else
        {
            //cout <<2 <<endl;
            Point p1 = s[0];
            Point p2 = s[1];
            Point m = dis2(a, p1) < dis2(a, p2) ? p1 : p2;
            //cout << m.x << " " << m.y << endl;
            Point sym = symPoint(a, c.O, m);
            //cout << sym.x  << " " << sym.y << endl;
            Line symLine(sym, m);
            Line te(b, m);
            //cout << symLine.angle << ' ' << te.angle << endl;
            //cout << te.V.x << ' ' <<te.V.y << endl;
            Line tee(m, b);
            //cout << tee.V.x << ' ' <<tee.V.y << endl;
            if(fabs(symLine.angle - te.angle) < eps  && tee.V.x * (b.x - m.x) >= 0 && tee.V.y * (b.y - m.y) >= 0) f = true;
        }
        cout<<"Case #"<<cnt++<<": ";
        if(f) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
/*
2
0 0 1
-1 2 1 -1
1 2
 && te.V.x * (b.x - a.x) >= 0 && te.V.y * (b.y - a.y) >= 0
*/
