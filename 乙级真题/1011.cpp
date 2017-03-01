#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstring>
#include<map>
#include<sstream>
using namespace std;
long long a,b,c,n;
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>a>>b>>c;
    if (a+b>c)
    cout<<"Case #"<<i<<": true\n";
    else
    cout<<"Case #"<<i<<": false\n";
  }
  return 0;
}
