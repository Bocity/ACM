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
#define mk make_pair
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

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

struct hotel {
    Point p;
    int c;
};
hotel a[20002];
hotel peo[20002];
int n, m;

int cmp(int i, int j) {
    return a[i].c > a[j].c;
}
int t;
int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            a[i].p.input();
            cin >> a[i].c;
        }
        // for (int i = 0; i < n; i++) {
        //     cout << a[i].p.x << " " << a[i].p.y << endl;
        //     cout << a[i].c << endl;
        // }
        for (int i = 0; i < m; i++) {
            peo[i].p.input();
            cin >> peo[i].c;
        }
        for (int i = 0; i < m; i++) {
            double min = 300000;
            int tmpp = 300000;
            for (int j = 0; j < n; j++) {
                Point tmp = a[j].p - peo[i].p;
                double dis = tmp.len();
                // cout << "dis:" << dis << endl;
                if (a[j].c > peo[i].c) {
                    continue;
                } else {
                    // cout << dis << "---" << min << "----" << j << endl;
                    if (dis < min) {
                        min = dis;
                        tmpp = j;
                    }
                }
            }
            cout << a[tmpp].p.x << " " << a[tmpp].p.y << " " << a[tmpp].c << endl;
        }
    }
    return 0;
}
