#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
bool a[200000];
int n,b,c;
int main()
{
  cin>>n;
  int t=0;
  for(int i=2;i<=n;i++)
  for (int j=2;j*i<=n;j++)
  a[i*j]=true;
  for(int i=2;i+2<=n;i++)
  if (!a[i]&&!a[i+2]) {t++;}
  cout<<t;
  return 0;
}
