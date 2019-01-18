#include<iostream>
#include <cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,x,y,p,sum=0,a[100000];
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
        cin>>a[i];
    }
    sort(a,a+x,cmp);
    int k=0;
    for (int i=0;i<x;i++)
    {

    k+=a[i];
    if (k>=y) {cout<<i+1;break;}
    }



    return 0;
}
