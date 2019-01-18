#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define PER(i,x,n) for(int i = (n)-1; i >= (x); --i)
#define inf 0x3f3f3f
#define eps 1e-9
#define PI acos(-1.0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9+7;
const int maxn = 1000 + 10;
struct point {
    double x, y;
};
point p[maxn], pp[maxn];
double s, a;

double dis(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
};

double tArea(point a, point b, point c) {
    double aa = dis(a, b), bb = dis(b, c), cc = dis(a, c);
    double p = (aa + bb + cc) / 2.0;
    return sqrt(p * (p - aa) * (p - bb) * (p - cc));
}

double area(int n) {
    double area = 0;
    for(int i = 1; i < n - 1; i++) {
        area += tArea(p[0], p[i], p[i + 1]);
    }
    return area;
}
double subArea(int n) {
    double area = 0;
    for(int i = 1; i < n; i++) {
        area += tArea(p[i], pp[2 * i], pp[2 * i - 1]);
    }
    area += tArea(p[0], pp[0], pp[2 * n - 1]);
    return area;
}

void newPoint(double s, int n) {
    for(int i = 0; i < n - 1; i++) {
        pp[2 * i].x = p[i].x + (p[i + 1].x - p[i].x) / s;
        pp[2 * i].y = p[i].y + (p[i + 1].y - p[i].y) / s;
        pp[2 * i + 1].x = p[i + 1].x - (p[i + 1].x - p[i].x) / s;
        pp[2 * i + 1].y = p[i + 1].y - (p[i + 1].y - p[i].y) / s;
    }
    pp[2 * n - 1].x = p[0].x + (p[n - 1].x - p[0].x) / s;
    pp[2 * n - 1].y = p[0].y + (p[n - 1].y - p[0].y) / s;
    pp[2 * n - 2].x = p[n - 1].x - (p[n - 1].x - p[0].x) / s;
    pp[2 * n - 2].y = p[n - 1].y - (p[n - 1].y - p[0].y) / s;
}

double  ck(double x, int n) {
    newPoint(x, n);
    double p = (s - subArea(n)) / s;
    return p;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> a >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    s = area(n);//原面积
    double l = 2.0, r = 1000.0;
    double m;
    int q=0;
    while(1||fabs(l-r)>eps) {
            q++;
    if(q>1000000)
        break;
        m = l / 2 + r / 2;
        double pos= ck(m,n);
        if(fabs(m - 1000.0) < eps) break;
        if(fabs(pos-a)<eps) {
            break;
        }
        else if(pos>a) {
            r=m;
        }
        else l=m;
    }
    cout << fixed << setprecision(10) << r << endl;
    return 0;
}
