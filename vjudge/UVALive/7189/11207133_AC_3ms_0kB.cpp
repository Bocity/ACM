#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2015 + 7;
const double eps = 1e-9;
int f[MAXN];
 
int sgn(double x) { return fabs(x) < eps ? 0 : x > 0 ? 1 : -1; }

struct Point {
  double x, y;
  Point(const double &x = 0, const double &y = 0) : x(x), y(y) {}
  Point operator - (const Point &p) { return Point(x - p.x, y - p.y); }
  double norm() { return sqrt(x * x + y * y); }
  friend double dis(const Point &a, const Point &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  }
  friend double dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
  }
  friend double det(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
  }
  friend double ang(Point a, Point b) {
    return acos(dot(a, b) / a.norm() / b.norm());
  }
};

Point p[MAXN], s[MAXN];

int relation(Point &a, Point &b, Point &c) {
  return sgn(det(b - a, c - a));
}

int ConvexHull(Point *p, int n) {
  sort(p, p + n, [&](Point &a, Point &b) {
    return sgn(a.x - b.x) == 0 ? a.y < b.y : a.x < b.x;
  });
  int top = 0;
  for(int i = 0; i < n; ++i) {
    while(top > 1 && relation(s[top - 2], s[top - 1], p[i]) < 0) top--;
    s[top++] = p[i];
  }
  int k = top;
  for(int i = n - 2; i >= 0; --i) {
    while(top > k && relation(s[top - 2], s[top - 1], p[i]) < 0) top--;
    s[top++] = p[i];
  }
  if(top > 1) top -= 1;
  return top;
}

bool check(int n) {
  double len = dis(s[0], s[n - 1]);
  for(int i = 0; i < n - 1; ++i) {
    double tt = dis(s[i], s[i + 1]);
    if(sgn(tt - len) != 0) return false;
  }
  return true;
}

int main() {
  #ifdef Zonda_R
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
  #endif
  int T;
  scanf("%d", &T);
  for(int cas = 1; cas <= T; ++cas) {
    int n;
    scanf("%d", &n);
    double x, y;
    for(int i = 0; i < n; ++i) {
      scanf("%lf %lf", &x, &y);
      p[i] = Point(x, y);
    }   
    int cnt = ConvexHull(p, n);
    if(cnt != n || !check(n)) { puts("NO"); }
    else { puts("YES"); }
  }
  return 0;
}