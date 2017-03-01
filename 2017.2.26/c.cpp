#include<iostream>
using namespace std;
int a[200000]={0},b[200000]={0},c[200000]={0},d[200000]={0},f[200000]={0},n,t=0,tt=0;
int p=0;
int l=0;
int main()
{

  cin>>n;
  for (int i=1;i<=n-1;i++)
  {
    cin>>a[i]>>b[i];
  }
  for (int i=1;i<=n;i++)
  {
    int q;
    cin>>q;
    c[i]=q;
    if (!d[c[i]])
    t++;
    d[c[i]]++;
  }
  int pp=0;
  for (int i=1;i<n;i++)
  {

    if (c[a[i]]!=c[b[i]])
    {
      pp++;
      f[a[i]]++;
      f[b[i]]++;
      //cout<<c[a[i]]<<" "<<c[b[i]]<<"\n";
    }
}

  for(int i=1;i<=n;i++)
      if (f[i]==pp)
      {
          cout<<"YES"<<"\n"<<i;
          return 0;
      }
      cout<<"NO";
    return 0;
}
