#include<iostream>
using namespace std;
int a[10000]={0},b[10000]={0},c[10000]={0},d[10000]={0},f[10000]={0},n,t=0,tt=0;
int p=0;
int main()
{

  cin>>n;
  for (int i=1;i<=n-1;i++)
  {
    cin>>a[i]>>b[i];
  }
  for (int i=1;i<=n-1;i++)
  {
    int q;
    cin>>q;
    c[i]=q;
    if (!d[c[i]])
    t++;
    d[c[i]]++;
  }
  if (t>3) cout<<"NO";
  else{
    int l=1;
  for (int i=1;i<=n;i++)
  {
    if (c[a[i]]!=c[b[i]])
    {
      tt++;
      f[l]=i;
      l++;
    }

  }
  int ll=-1;
  int rr=-11;
  int lll=-1;
  int rrr=-11;
  int llll=-1;
  int rrrr=-11;
  int lllll=-1;
  int rrrrr=-11;
  //cout<<a[f[1]]<<a[f[2]]<<b[f[1]]<<b[f[2]]<<"\n";
  //cout<<c[a[f[1]]]<<c[a[f[2]]]<<c[b[f[1]]]<<c[b[f[2]]];
  if (c[a[f[1]]]==c[a[f[2]]])
  {
  ll=a[f[1]];
  rr=a[f[2]];}
  if (c[a[f[1]]]==c[b[f[2]]])
  {
  lll=a[f[1]];
  rrr=b[f[2]];}
  if (c[b[f[1]]]==c[a[f[2]]])
  {
  llll=b[f[1]];
  rrrr=a[f[2]];}
  if (c[b[f[1]]]==c[b[f[2]]])
  {
  lllll=b[f[1]];
  rrrrr=b[f[2]];}
  if (ll==-1&&lll==-1&&llll==-1&&lllll==-1)
  tt=11;
  if (ll==rr) p=ll;
  if (lll==rrr) p=lll;
  if (llll==rrrr) p=llll;
  if (lllll==rrrrr) p=lllll;
  if (p==0) tt=10;
  if (tt>3||l>=3) cout<<"NO";
  else
  cout<<"YES\n"<<p;
}
    return 0;
}
