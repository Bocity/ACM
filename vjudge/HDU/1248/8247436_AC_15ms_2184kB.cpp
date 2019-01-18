#include<iostream>
#include <cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,c[4]={150,200,350},f[100000],w;
int main()
{
  cin>>n;
  for (int i=1;i<=n;i++)
  {
  cin>>w;
  memset(f,0,sizeof(f));
  for (int j=0;j<3;j++)
  for (int k=0;k<=w;k++)
  {
    if (k-c[j]>=0)
    f[k]=max(f[k],f[k-c[j]]+c[j]);
  }
  cout<<w-f[w]<<endl;

}
  return 0;
}
