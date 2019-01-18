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
        sort(polong +1,polong  + 3*n+1,cmp);
        for(long long i=1;i<=3*n;i+=3)
        {
            for(long long j=0;j<3;j++)
            {
                cout<<polong [i+j].id<<" ";
            }
            cout<<endl;
        }
    }


}
