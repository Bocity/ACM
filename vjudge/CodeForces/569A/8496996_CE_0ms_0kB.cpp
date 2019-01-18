#include<iostream>
using namespace std;
double q,T,s,fin;
int ans;
int main
{
  cin>>T>>s>>q;
  fin=s;
while (fin<T)
{
   fin+=q*s;
   s=fin;
   ans++;
}
if (ans==0) cout<<1;
else
cout<<ans;
}