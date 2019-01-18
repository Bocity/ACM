#include<iostream>
using namespace std;
double q,T,s,fin;
int ans;
int main()
{
  cin>>T>>s>>q;
  fin=0;
  ans=0;
while (fin<T)
{
   fin+=q*s;
   s=fin;
   ans++;
}
cout<<ans;
}