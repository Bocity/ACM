#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int n,a,b,c;
int main()
{
  cin>>n;
  a=n/100;
  b=n%100/10;
  c=n%10;
  for (int i=1;i<=a;i++)
  cout<<"B";
  for (int i=1;i<=b;i++)
  cout<<"S";
  for (int i=1;i<=c;i++)
  cout<<i;
  return 0;
}
