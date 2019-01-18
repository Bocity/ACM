#include<iostream>
using namespace std;
long long x,y,z;
int a[10]={1,4,6,5,2};
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
  z=0;
  cin>>x;
  z=x/6;
  z+=a[x-z*6-1];
  cout<<z<<"\n";
  }
  return 0;
}
