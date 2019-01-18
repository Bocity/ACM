#include<iostream>
#include <cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x,y,p,sum=0,a[100000],minn,xx;
string s;
bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    cin>>x>>y;
    for (int i=0;i<x;i++)
    {
        minn=99999;
    for (int j=1;j<=y;j++)
    {
        cin>>xx;
        minn=min(minn,xx);
    }
    a[i]=minn;
    }
    sort(a,a+x,cmp);
    cout<<a[0];

    return 0;
}
