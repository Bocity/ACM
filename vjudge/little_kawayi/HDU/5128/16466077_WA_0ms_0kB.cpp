#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-10 , pi = acos(-1.0);
inline int dcmp(double x) {
    return (x > eps) - (x < -eps);
}
struct Point {
    double x , y;
    Point (double x = 0 , double y = 0) : x(x) , y(y) {}
    void input() {
        scanf("%lf%lf",&x,&y);
    }
    bool operator < (const Point& R) const {
        if (dcmp(x - R.x) == 0)
            return dcmp(y - R.y) < 0;
        return dcmp(x - R.x) < 0;
    }
    bool operator == (const Point& R) const {
        return dcmp(x - R.x) == 0 && dcmp(y - R.y) == 0;
    }
    Point operator + (const Point& R) const {
        return Point(x + R.x , y + R.y);
    }
    Point operator - (const Point& R) const {
        return Point(x - R.x , y - R.y);
    }
    Point operator * (const double& R) const {
        return Point(x * R , y * R);
    }
    Point operator / (const double& R) const {
        return Point(x / R , y / R);
    }
    double operator ^ (const Point& R) const {
        return x * R.y - y * R.x;
    }
    double operator % (const Point& R) const {
        return x * R.x + y * R.y;
    }
    double len() {
        return sqrt(*this % *this);
    }
    double angle() {
        return atan2(y , x);
    }
};
vector<Point>point;
struct node{
    Point p[4];
};
vector<node> jz;
bool SegmentProperIntersection(Point a1 , Point a2 , Point b1 , Point b2) {
    double c1 = (a2 - a1) ^ (b1 - a1);
    double c2 = (a2 - a1) ^ (b2 - a1);
    if (dcmp(c1) == 0 && dcmp(c2) == 0) {
        if (a2 < a1) swap(a1 , a2);
        if (b2 < b1) swap(b1 , b2);
        return max(a1 , b1) < min(a2 , b2);
    }
    double c3 = (b2 - b1) ^ (a1 - b1);
    double c4 = (b2 - b1) ^ (a2 - b1);
    return dcmp(c1) * dcmp(c2) <= 0 && dcmp(c3) * dcmp(c4) <= 0;
}
bool check(int a,int b)
{
    if(
    SegmentProperIntersection(jz[a].p[0],jz[a].p[1],jz[b].p[0],jz[b].p[1])
    ||SegmentProperIntersection(jz[a].p[0],jz[a].p[1],jz[b].p[0],jz[b].p[2])
    ||SegmentProperIntersection(jz[a].p[0],jz[a].p[1],jz[b].p[2],jz[b].p[3])
    ||SegmentProperIntersection(jz[a].p[0],jz[a].p[1],jz[b].p[1],jz[b].p[3])

    ||SegmentProperIntersection(jz[a].p[0],jz[a].p[2],jz[b].p[0],jz[b].p[1])
    ||SegmentProperIntersection(jz[a].p[0],jz[a].p[2],jz[b].p[0],jz[b].p[2])
    ||SegmentProperIntersection(jz[a].p[0],jz[a].p[2],jz[b].p[2],jz[b].p[3])
    ||SegmentProperIntersection(jz[a].p[0],jz[a].p[2],jz[b].p[1],jz[b].p[3])

    ||SegmentProperIntersection(jz[a].p[3],jz[a].p[1],jz[b].p[0],jz[b].p[1])
    ||SegmentProperIntersection(jz[a].p[3],jz[a].p[1],jz[b].p[0],jz[b].p[2])
    ||SegmentProperIntersection(jz[a].p[3],jz[a].p[1],jz[b].p[2],jz[b].p[3])
    ||SegmentProperIntersection(jz[a].p[3],jz[a].p[1],jz[b].p[1],jz[b].p[3])

    ||SegmentProperIntersection(jz[a].p[3],jz[a].p[2],jz[b].p[0],jz[b].p[1])
    ||SegmentProperIntersection(jz[a].p[3],jz[a].p[2],jz[b].p[0],jz[b].p[2])
    ||SegmentProperIntersection(jz[a].p[3],jz[a].p[2],jz[b].p[2],jz[b].p[3])
    ||SegmentProperIntersection(jz[a].p[3],jz[a].p[2],jz[b].p[1],jz[b].p[3]))
    return 0;
    else
        return 1;

}
long long getans(int a,int b)
{
    long long ans1=0;
    ans1+=abs(jz[a].p[0].x-jz[a].p[3].x)*abs(jz[a].p[0].y-jz[a].p[3].y);
    ans1+=abs(jz[b].p[0].x-jz[b].p[3].x)*abs(jz[b].p[0].y-jz[b].p[3].y);
    return ans1;
}
int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        point.clear();
        jz.clear();
        map<Point,bool> use;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            point.push_back(Point{x,y});
            use[Point{x,y}]=1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    bool flag=0;
                    Point pos[4];
                    pos[0].x=point[i].x,pos[0].y=point[i].y;
                    pos[2].x=point[j].x,pos[2].y=point[j].y;
                    pos[1].x=point[j].x,pos[3].y=point[j].y;
                    pos[3].x=point[i].x,pos[1].y=point[i].y;
                    for(int k=0;k<4;k++)
                    {
                        if(use[pos[k]]==0)
                            flag=1;
                    }
                    for(int k=0;k<4;k++)
                    {
                        for(int l=0;l<4;l++)
                        {
                            if(k!=l&&pos[k].x==pos[l].x&&pos[k].y==pos[l].y)
                            {
                                flag=1;
                            }
                        }
                    }
                    if(flag==0)
                    {
                        node pos1;
                        for(int k=0;k<4;k++)
                            pos1.p[k].x=pos[k].x,pos1.p[k].y=pos[k].y;
                        sort(pos1.p,pos1.p+4);
                        jz.push_back(pos1);
                    }
                }
            }
        }

//        for(auto e:use)
//            cout<<e.first.x<<" "<<e.first.y<<" "<<e.second<<endl;
        long long ans=-1;
//        for(int i=0;i<jz.size();i++)
//        {
//            cout<<i<<" ";
//            for(int j=0;j<4;j++)
//                cout<<jz[i].p[j].x<<" "<<jz[i].p[j].y<<" ";
//            cout<<endl;
//        }
        for(int i=0;i<jz.size();i++)
        {
            for(int j=0;j<jz.size();j++)
            {
                if(i!=j&&check(i,j))
                {
                    ans=max(ans,getans(i,j));
//                    cout<<i<<" "<<j<<" "<<getans(i,j)<<endl;
                }

            }
        }
        if(ans==-1)
            cout<<"imp"<<endl;
        else
        cout<<ans<<endl;
    }

}
