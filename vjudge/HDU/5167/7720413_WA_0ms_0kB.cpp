#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
long long f[100];
long long n,m,sum=0,x,y,xx;
bool dfs(long long x)
{
    if (x==1)return true;
    if (x==0) return true;
    for (int i=3;f[i]<=x;i++)
    {
        if (x==f[i]) return true;
    }
        for (int i=3;f[i]<=x;i++)
    {
            if (x%f[i]==0)
            return (dfs(x/f[i]));
    }

    return false;
}
int main()
{

f[0]=0;
f[1]=1;
for (int i=2;i<=50;i++)
    f[i]=f[i-1]+f[i-2];
cin>>n;
for (int i=1;i<=n;i++)
{
    cin >>xx;
    if (dfs(xx)) cout<<"Yes\n";
    else cout<<"No\n";

}
	return 0;
}
