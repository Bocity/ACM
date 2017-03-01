#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int maxx,n;
bool a[1000000]={0};
int b[10000]={0};
void check(int x){
  if (a[x]) return ;
  while (x!=1)
  {
    x=(x%2)?(3*x+1)/2:x/2;
    if (a[x] ) break;
    a[x]=true;
  }
  return ;
}
int main()
{
  cin>>n;
  for (int i=0;i<n;i++)
  {
    cin>>b[i];
    check(b[i]);
  }
  sort(b,b+n);
  bool t=false;
  for (int i=n-1;i>=0;i--)
  {
    if (!a[b[i]]&&t)
    {
      cout<<" "<<b[i];
    }
    if (!a[b[i]]&&!t)
    {
      cout<<b[i];
      t=true;
    }

  }
  return 0;
}
