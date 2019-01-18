#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
long long f[1000];
long long n,m,sum=0,x,y,xx;
bool dfs(long long x,long long pos)
{
    if (x==1)return true;
    if (x==0) return true;
    for (int i=pos;i>=3;i--)
    {
       if (x%f[i]==0)
        if  (dfs(x/f[i],i))
            return true;
    }

    return false;
}
int main()
{

f[0]=0;
f[1]=1;
for (int i=2;i<=100;i++)
    f[i]=f[i-1]+f[i-2];
cin>>n;
for (int i=1;i<=n;i++)
{
    scanf("%lld",&xx);
    if (dfs(xx,100)) printf("Yes\n");
    else printf("No\n");

}
	return 0;
}
