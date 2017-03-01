#include<iostream>
using namespace std;
int a[10000],b[10000],a1[10000],b1[10000],n,l;
int main()
{
  cin>>n>>l;
  for (int i=1;i<=n;i++)
  cin>>a[i];
  for (int i=2;i<n;i++)
  a1[i]=a[i]-a[i-1];
  a1[n]=l-a[n]+a[1];
  for (int i=1;i<=n;i++)
  cin>>b[i];
  for (int i=2;i<n;i++)
  b1[i]=b[i]-b[i-1];
  b1[n]=l-b[n]+b[1];
  bool t=false;
    for (int i=1;i<=n;i++)
    {
      int tt=0;
      for(int j=1;j<=n;j++)
          {

              int x=j;
              int y=j+i;
              if(y>=n)
                y-=n;
              if(a1[x]!=b1[y])
              {
                  tt=1;
                  break;
              }
              if(tt==0)
                {
                    t=1;
                    break;
                }
          }
    }
    if (!t) cout<<"NO";
    else cout<<"YES";
  return 0;
}
