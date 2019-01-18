#include<iostream>
#include<algorithm>
using namespace std;
int a[200000],n;
int main()
{

  cin>>n;
  for (int i=1;i<=n;i++)
  {
    cin>>a[i];
  }
  bool t=false;
  sort(a+1,a+n+1);
  for (int i=3;i<=n;i++)
  {
    if (a[i-2]+a[i-1]<=a[i])
    t=true;
  }
  if (t) cout<<"YES";
  else cout<<"NO";
    return 0;
}
