#include<iostream>
using namespace std;
int a,b,c,n;
bool f[100000];
int main()
{
int t=0;
  cin>>a>>b>>c;
  for (int i=1;i*a<=c;i++)
  {
    f[i*a]=true;
  }
  for (int i=1;i*b<=c;i++)
  {
    if (f[i*b]) t++;
  }
  cout<<t;
    return 0;
}
