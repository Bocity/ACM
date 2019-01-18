#include <bits/stdc++.h>
#define REP(i,x,n) for(int i = x; i < n; ++i)
#define endl "\n"
#define y1 aisuhfiweueshewinhehhf
#define mems(a) memset(a,0,sizeof a)
#define sqr(x) ((x)*(x))
using namespace std;
const double eps = 1e-5, pi = acos(-1.0);
inline int dcmp(double x) {
    return (x > eps) - (x < -eps);
}
int t,n,anss;
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


// 向量的极角，[-pi,pi)
double Angle(Point V) {
    return atan2(V.y, V.x);
}
// 两个向量的夹角，不分正负[0,pi)
double Angle(Point A, Point B) {
    return acos((A % B) / A.len() / B.len());
}
// 逆时针旋转
Point Rotate(Point A, double rad) {
    double Sin = sin(rad), Cos = cos(rad);
    return Point(A.x * Cos - A.y * Sin, A.x * Sin + A.y * Cos);
}
// 向量的单位法向量，利用旋转得到
Point Normal(Point A) {
    double L = A.len();
    return Point(-A.y / L, A.x / L);
}
// 直线交点，v和w为两个直线的方向向量，
// 设交点的参数为P+vt,Q+wt,连立方程解t
// 线段，射线对这个t的参数有限制，很好理解。
Point GetLineIntersection(Point P, Point v, Point Q, Point w) {
    Point u = P - Q;
    double t1 = (w ^ u) / (v ^ w);
    return P + v * t1;
}
// 点到直线有向距离，这里直线是用两个点表示的
double DistancePointToLine(Point P, Point A, Point B) {
    Point v = B - A;
    return (v ^ (P - A)) / v.len();
}
// 点到线段距离，就是上面的代码判断一下P在AB上投影的位置。
double DistancePointToSegment(Point P, Point A, Point B) {
    if (A == B) return (P - A).len();
    Point v1 = B - A, v2 = P - A, v3 = P - B;
    if (dcmp(v1 % v2) < 0) return v2.len();
    if (dcmp(v1 % v3) > 0) return v3.len();
    return fabs(v1 ^ v2) / v1.len();
}
// 返回点在直线上的投影
Point GetLineProjection(Point P, Point A, Point B) {
    Point v = B - A;
    return A + v * (v % (P - A) / (v % v));
}
// 判断线段是否相交，没有考虑共线的情况。
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
    double c1 = (a2 - a1) ^ (b1 - a1);
    double c2 = (a2 - a1) ^ (b2 - a1);
    double c3 = (b2 - b1) ^ (a1 - b1);
    double c4 = (b2 - b1) ^ (a2 - b1);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
// 点是否在线段上,判定方式为到两个端点的方向是否不一致。
bool OnSegment(Point P, Point a1, Point a2) {
    double len = (P - a1).len();
    if (dcmp(len) == 0) return true;
    a1 = a1 - P, a2 = a2 - P;
    return dcmp((a1 ^ a2) / len) == 0 && dcmp(a1 % a2) <= 0;
}
struct circle{
    double R;
    bool fl;
    Point cir;
    bool operator==(const circle &te) const{
        return this->cir==te.cir && dcmp(this->R - te.R) == 0;
    }
};
circle calc(Point x,Point y,Point z){
    if (y < x) swap(x,y);
    if (z < x) swap(x,z);
    if (z < y) swap(y,z);
    circle temp;
    double a,b,r2;
    double x1 = x.x,y1 = x.y;
    double x2 = y.x,y2 = y.y;
    double x3 = z.x,y3 = z.y;
    if (OnSegment(x,y,z)){
        temp.cir.x = (x.x + z.x) / 2;
        temp.cir.y = (x.y + z.y) / 2;
        temp.R = sqrt(sqr(x.x-z.x)+sqr(x.y-z.y))/2;
        return temp;
    }

    if ((2.0*((x3-x1)*(y2-y1)-(x2-x1)*(y3-y1)))==0||(2.0*((y3-y1)*(x2-x1)-(y2-y1)*(x3-x1)))==0){
        return temp;
    }
    a=((y2-y1)*(y3*y3-y1*y1+x3*x3-x1*x1)-(y3-y1)*(y2*y2-y1*y1+x2*x2-x1*x1))/(2.0*((x3-x1)*(y2-y1)-(x2-x1)*(y3-y1)));
    b=((x2-x1)*(x3*x3-x1*x1+y3*y3-y1*y1)-(x3-x1)*(x2*x2-x1*x1+y2*y2-y1*y1))/(2.0*((y3-y1)*(x2-x1)-(y2-y1)*(x3-x1)));
    r2=(x1-a)*(x1-a)+(y1-b)*(y1-b);
    temp.cir.x = a;
    temp.cir.y = b;
    temp.R = r2;
    return temp;
} 
typedef long long ll;
vector<Point> q;
vector<circle> ans;
int main(){
    srand(time(NULL));
    scanf("%d",&t);
    Point temp;
    bool hav = false;
    while(t--){
        anss = -1;
        q.clear();
        ans.clear();
        scanf("%d",&n);
        REP(i,0,n){
            scanf("%lf%lf",&temp.x,&temp.y);
            q.push_back(temp); 
        }
        if (n==1){
            printf("%.5f %.5f %.5f\n",temp.x,temp.y,0);
            continue;
        }
        if (n==2){
            printf("%.5f %.5f %.5f\n",(q[0].x+q[1].x)/2,(q[0].y+q[1].y)/2,sqrt(sqr(q[0].x-q[1].x)+sqr(q[0].y-q[1].y))/2);
            continue;
        }
        int siz = q.size();
        int pos1 = 0,pos2 = 0,pos3 = 0;
        REP(i,0,500){
                pos1 = rand() % siz;
                pos2 = rand() % siz;
                pos3 = rand() % siz;
                while(pos1 == pos2 || pos1 == pos3|| pos3 == pos2){
                    pos1 = rand() % siz;
                    pos2 = rand() % siz;
                    pos3 = rand() % siz;
                }
            ans.push_back(calc(q[pos1],q[pos2],q[pos3]));
        }
       int iii = 0;
       REP(i,0,500){
           iii = 0;
           REP(j,0,siz){
               if (dcmp(sqrt(sqr(q[j].x-ans[i].cir.x)+sqr(q[j].y - ans[i].cir.y)) - ans[i].R)==0){
                   iii++;
               }
               if (iii >= (n+1) / 2){
                   break;
               }
           }
           if (iii >= (n+1)/2){
            printf("%.5f %.5f %.5f\n",ans[i].cir.x,ans[i].cir.y,ans[i].R);
            hav = true;
            break;
           }
          //printf("%.5f %.5f %.5f %d\n",ans[i].cir.x,ans[i].cir.y,ans[i].R,iii);
       }
    //    if (!hav) printf("fuck\n");
    //    hav = false;
    }
    return 0;
}