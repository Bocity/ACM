#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstring>
#include<map>
int a[10]={0};
using namespace std;
string s;
int n,t;
int k,l,k1,l1;
bool pta(char x)
{
  if (x=='P'||x=='T'||x=='A')return true;
  return false;
}
int main()
{
  cin>>n;
for (int i = 0; i < n; i++) {
  cin>>s;
  t=0;
  memset(a,0,sizeof(a));
  k=l=k1=l1=0;
  for (int j = 0; j < s.length(); j++) {
    if (!pta(s[j]))
    {
      cout<<"NO\n";
      goto x;
    }
    if (s[j]=='P'||s[j]=='T') t++;
    else
    a[t]++;
    if (s[j]=='P') {k1=j;k++;}
    if (s[j]=='T') {l1=j;l++;}

  }
  if (k1>l1||k!=1||l!=1)
  {
    cout<<"NO\n";
    continue;
  }
  if ((a[0]==a[2]&&a[1]==1)||(a[0]*a[1]==a[2]&&a[1]!=0)||(a[0]==a[2]&&a[0]==0&&a[1]>0)){cout<<"YES\n";continue;}
  else {cout<<"NO\n";continue;}
  x:;

}
  return 0;
}
