#include<iostream>
using namespace std;
int a[120000],n;
int main()
{

  cin>>n;
  for (int i=1;i<=n;i++)
  {
    cin>>a[i];
  }
  bool t=false;
  for (int i=3;i<=n;i++)
  {
    if (a[i-2]+a[i-1]<=a[i])
    t=true;
  }
  if (t) cout<<"YES";
  else cout<<"NO";
    return 0;
}
