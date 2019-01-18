#include<iostream>
using namespace std;
int a[10000],b[10000],n,l;
int main()
{
  cin>>n>>l;
  for (int i=1;i<=n;i++)
  cin>>a[i];
  for (int i=1;i<=n;i++)
  cin>>b[i];
  bool t=false;
  for (int i=0;i<=l;i++)
  {
    if (a[1]+i==b[1])
    {
      t=true;
      for (int j=1;j<=n;j++)
      if (a[j]+i!=b[j])
      t=false;
    }
    if (a[1]==b[1]+i)
    {
      t=true;
      for (int j=1;j<=n;j++)
      if (a[j]!=b[j]+i)
      t=false;
    }
  }
  if (!t) cout<<"NO";
  else cout<<"YES";

  return 0;
}
