#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int a[200000];
int n,b,c,m;
int main()
{
  cin>>n>>m;
  m=m%n;
  for (int i=1;i<=n;i++)
  cin>>a[i];
  for (int i=n;i>=1;i--)
  a[i+m]=a[i];
  for (int i=n+1;i<=n+m;i++)
  a[i-n]=a[i];
  for (int i=1;i<n;i++)
  cout<<a[i]<<" ";
  cout<<a[n];
  return 0;
}
