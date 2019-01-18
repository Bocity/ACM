#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include<algorithm>
using namespace std;
bool vis[101][101]={0},tr=false;
int n,m,sum=0,y,b[2000],T,a;

int dfs(int x,int k)
{
    int p1,p2;
    if (x%b[k]==0) {tr=true; return 1;}
    if (k==n) return 100;

    p1=dfs(x%b[k],k+1)+1;
    p2=dfs(x,k+1);
    cout<<x<<":x"<<k<<":k"<<"  "<<p1<<"--"<<p2<<"\n";
    return min(p1,p2);
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
        tr=false;
        for (int j=1;j<=n;j++)
        cin>>b[j];
        sum=dfs(a,1);
        if (tr)
        cout<<sum<<"\n";
        else
             cout<<-1<<"\n";
        tr=false;
    }


	return 0;
}
