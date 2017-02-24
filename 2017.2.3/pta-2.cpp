#include<iostream>
using namespace std;
string s;
int a[10],t;
string b[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main()
{
cin>>s;
int m=0;
for (int i=0;i<s.length();i++)
{
  m+=s[i]-'0';
}
int j=0;
while (m>0)
{
  t=m%10;
  m/=10;
  j++;
  a[j]=t;
}
for (int i=j;i>=2;i--)
{
  cout<<b[a[i]]<<" ";
}
cout<<b[a[1]];
  return 0;
}
