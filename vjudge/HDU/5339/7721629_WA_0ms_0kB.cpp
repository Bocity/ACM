#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include<algorithm>
using namespace std;
bool vis[101][101]={0};
int n,m,sum=0,x,y,b[2000],T,a;
int dfs(int x,int k)
{
    if (x==0) return 1;
    if (x%b[k]==0) return 1;
    if (k==n&&x%b[k]!=0) {return -n;}
    for (int i=k;i<=n;i++)
    {
        return dfs(x%b[i],k+1)+1;
    }
	return 0;
}
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
	cin >> T;
	for (int i=1;i<=T;i++)
    {
        cin>>n>>a;
        for (int j=1;j<=n;j++)
        cin>>b[j];
        sort(b+1,b+n+1,cmp);
        sum=dfs(a,1);
        cout<<sum<<"\n";
    }


	return 0;
}
