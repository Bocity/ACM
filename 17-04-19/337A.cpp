#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

ll a[10000],minn,maxx,ans,anss,m,n;
int main()
{
    cin>>n>>m;
    anss=1e9+7;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
       for(int j=1;j<=m;j++)
       {
           if (i==j) continue;
           maxx=max(a[i],a[j]);
           minn=min(a[i],a[j]);
           ans=0;
           for(int k=1;k<=m;k++)
           {
               if (k==i||k==j) continue;
               if (a[k]<=maxx&&a[k]>=minn) ans++;
           }
           if (ans>=n-2) anss=min(anss,maxx-minn);
       }
    }
    cout<<anss;
}
//  7 1 2 4  7   
//    9 1 2 6
//    1 0 0
//    0 0 1
//    0 1 0
//    1 1 1
//    1 1 1 0 0 0
//    1 0 0 0 0 0
//    0 1 0 0 0 0
//    0 0 1 0 0 0
//    1 0 1 0 1 1
//    1 0 0 0 0 1
//    