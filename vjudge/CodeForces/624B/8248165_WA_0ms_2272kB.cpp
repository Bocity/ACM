#include<iostream>
#include<string.h>
#include<cstring>
#include<algorithm>
using namespace std;
long long n,x,maxx,p=0;
long long a[30000];
bool cmp(long long x,long long y)
{
    return x>y;
}
int main()
{
    cin >>n;
   for (int i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n,cmp);
    p+=a[0];
    for (int i=1;i<n;i++)
    {
       if (a[i]==a[i-1])a[i]--;
       if (a[i]>=0)
        p+=a[i];
    }
    cout<<p;

    return 0;
}
