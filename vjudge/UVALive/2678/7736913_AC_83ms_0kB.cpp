#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include<algorithm>
using namespace std;
long long m,n,a[200000],b[200000];
int minn;


int cha(long long k,int l,int r,int t)
{
    int mid =(l+r)/2;
    if (r-l<=1)
    {
        if ((b[l]-k)>=m) return (l-t);
        if ((b[r]-k)>=m) return (r-t);
        return n+1;
    }
    if ((b[mid]-k)<=m) return cha(k,mid,r,t);
    return cha(k,l,mid,t);
}
int main()
{
  while(cin>>n>>m)
  {
      minn=n+1;
      memset(b,0,sizeof(b));
      for (int i=1;i<=n;i++)
      {
          cin>>a[i];
          b[i]+=b[i-1]+a[i];
      }
      for (int i=1;i<=n;i++)
      {
        minn=min(minn,cha(b[i-1],i,n,i-1));
      }
      if (b[n]<m) cout<<0<<"\n";
      else
      cout<<minn<<"\n";
  }
return 0;
}
