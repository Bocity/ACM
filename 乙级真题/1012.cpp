#include<iostream>
#include<string.h>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
#include<sstream>
using namespace std;
long long a[10]={0},b=0,c,n,x;
double xx=0;
int main()
{
  cin>>n;
  int q=1;
  int k=0;
  for(int i=1;i<=n;i++)
  {
    cin>>x;
    if (x%10==0)a[1]+=x;
    if (x%5==1){
      k=1;
      if (q) {
        a[2]+=x;
        q=0;
      }
      else{
        a[2]-=x;
        q=1;
      }
      }
      if (x%5==2)a[3]++;
      if (x%5==3){xx+=x;b++;}
      if (x%5==4)a[5]=max(a[5],x);
    }
    //cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<xx<<" "<<a[5]<<" ";
    string s[6];
    if (a[1]==0) cout<<"N"<<" ";
    else cout<<a[1]<<" ";
    if (a[2]==0&&!k) cout<<"N"<<" ";
    else cout<<a[2]<<" ";
    if (a[3]==0) cout<<"N"<<" ";
    else cout<<a[3]<<" ";
    if (xx==0) cout<<"N"<<" ";
    else printf("%.1lf ",xx/b);
    if (a[5]==0) cout<<"N";
    else cout<<a[5];
    return 0;
  }
