#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstring>
#include<map>
#include<sstream>
using namespace std;
int a[200000];
int n,b,c,m,x,y;
string s;
int main()
{
  int maxx=-1;
  while(cin>>x>>y)
  {
    a[y]=x;
    maxx=max(maxx,y);
  }
  bool t=false;
  if (maxx==0)
  cout<<"0 0";
  else
  for (int i=maxx;i>0;i--)
  {
    if (a[i]!=0&&t)
    {
      cout<<" "<<a[i]*i<<" "<<i-1;
    }
    if (a[i]!=0&&!t)
    {

      cout<<a[i]*i<<" "<<i-1;
      t=true;
    }
  }
  return 0;
}
