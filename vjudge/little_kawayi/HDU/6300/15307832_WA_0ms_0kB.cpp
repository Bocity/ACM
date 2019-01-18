#include<bits/stdc++.h>
using namespace std;
const long long maxn=1010;
struct node
{
    long long x,y,id;
}polong [3*maxn];
node d;
bool cmp(node a,node b)
{
   return ((a.x-d.x)*(b.y-d.y)-(a.y-d.y)*(b.x-d.x))>0;
}

int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        d.x=1e9;
        long long n;
        cin>>n;
        for(long long i=1;i<=3*n;i++)
        {
            cin>>polong [i].x>>polong [i].y;
            if(polong[i].x<d.x)
            {
                d.x=polong[i].x;
                d.y=polong[i].y;
            }
            polong [i].id=i;
        }
//        cout<<d.x<<" "<<d.y<<endl;
        sort(polong +1,polong  + 3*n+1,cmp);
//        for(int i=1;i<=3*n;i++)
//            cout<<polong[i].x<<" "<<polong[i].y<<endl;
        for(long long i=1;i<=3*n;i+=3)
        {
            cout<<polong[i].id<<" "<<polong[i+1].id<<" "<<polong[i+2].id;
            cout<<endl;
        }
    }


}
/*
10
2
1 1
3 1
2 5
1 3
2 2
4 2
*/
