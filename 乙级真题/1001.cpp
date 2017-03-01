#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int m=0;
  while (n!=1)
  {
    n=(n%2)?(3*n+1)/2:n/2;
    m++;
  }
  cout<<m;
  return 0;
}
