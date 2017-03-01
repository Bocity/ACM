#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstring>
#include<map>
#include<sstream>
using namespace std;
string a[200000];
int n,b,c,m;
string s;
int main()
{
  getline(cin,s);
  stringstream my(s);
  int i=0;
  while(my>>a[i])
  {
    i++;
  }
  for (int j=i-1;j>0;j--)
  cout<<a[j]<<" ";
  cout<<a[0];
  return 0;
}
