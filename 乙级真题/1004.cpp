#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
string s;
int n,m,t;
string k,l;
struct p{
  string name,numb;
  int x;
};
p a[10000];
bool cmp(p x,p y)
{
  return x.x>y.x;
}
int main()
{
  cin>>n;
for (int i = 0; i < n; i++) {
  cin>>k>>l>>m;
  a[i].name=k;
  a[i].numb=l;
  a[i].x=m;
  /* code */
}
sort(a,a+n,cmp);
cout<<a[0].name<<" "<<a[0].numb<<"\n";
cout<<a[n-1].name<<" "<<a[n-1].numb;

  return 0;
}
