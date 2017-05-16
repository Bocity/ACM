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
using namespace std;
double dis(double x1,double x2,double y1,double y2) {return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));}
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
class Point {
public:
    Point(){};
    Point(double newX,double newY);
    void setValue(double newX,double newY);
    double getX(){
        return x;
    }
    double getY()
    {
        return y;
    }
    double getDistance(Point &p2){
        return dis(p2.x,this->x,p2.y,this->y);
    }
private:
    double x,y;
};
class Triangle
{
public:
    Triangle(Point &p1,Point& p2,Point &p3){this->p1=p1;this->p2=p2;this->p3=p3;}
    double getArea(){
        double x1,x2,x3,y1,y2,y3,x4,x5,y4,y5;
        x1=p1.getX();
        x2=p2.getX();
        x3=p3.getX();
        y1=p1.getY();
        y2=p2.getY();
        y3=p3.getY();
        x4=x2-x1;y4=y2-y1;
        x5=x3-x1;y5=y3-y1;
        return abs((x4*y5-y4*x5)/2);
    }
    double getPerimeter()
    {
        double x1,x2,x3,y1,y2,y3,x4,x5,y4,y5;
        x1=p1.getX();
        x2=p2.getX();
        x3=p3.getX();
        y1=p1.getY();
        y2=p2.getY();
        y3=p3.getY();
        return (dis(x1,x2,y1,y2)+dis(x1,x3,y1,y3)+dis(x2,x3,y2,y3));

    }
private:
    Point p1,p2,p3;
};
void Point::setValue(double newX,double newY)
{
    x=newX;
    y=newY;
}
Point::Point(double newX,double newY)
{
    x=newX;
    y=newY;
}
int main()
{
    Point p1(0,0),p2(0,3),p3(4,0);
    Triangle t(p1,p2,p3);
    cout<<"Area: "<<t.getArea()<<endl;
    cout<<"Peimeter: "<<t.getPerimeter()<<endl;
    double x,y;
    while (1)
    {
        cout<<"输入三个顶点:";
        cin>>x>>y;
        p1.setValue(x,y);
        cin>>x>>y;
        p2.setValue(x,y);
        cin>>x>>y;
        p3.setValue(x,y);
        Triangle tt(p1,p2,p3);
        cout<<"Area: "<<tt.getArea()<<endl;
        cout<<"Peimeter: "<<tt.getPerimeter()<<endl;
    }
    return 0;
}