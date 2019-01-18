#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
char a[101][101];
bool vis[101][101]={0};
int n,m,sum=0,x,y;
void dfs(int x,int y)
{
	if (vis[x][y]) return ;
	vis[x][y]=true;
	if (y+1<=n && a[x][y+1]=='W') dfs(x,y+1);
	if (x+1<=m && a[x+1][y]=='W') dfs(x+1,y);
	if (y-1>=1 && a[x][y-1]=='W') dfs(x,y-1);
	if (x-1>=1 && a[x-1][y]=='W') dfs(x-1,y);
    if (x-1>=1 && y-1>=1&&a[x-1][y-1]=='W') dfs(x-1,y-1);
    if (x-1>=1 && y+1<=n&&a[x-1][y+1]=='W') dfs(x-1,y+1);
    if (y-1>=1 && x+1<=m&&a[x+1][y-1]=='W') dfs(x+1,y-1);
    if (y+1<=n && x+1<=m&&a[x+1][y+1]=='W') dfs(x+1,y+1);
	return ;
}
int main()
{
	cin >> m>> n ;
		sum=0;
		memset(vis,false,sizeof(vis));
		for (int i=1;i<=m;i++)
        {
			for (int j=1;j<=n;j++)
			{
				cin>>a[i][j];
			}
			getchar();
        }


        for (int i=1;i<=m;i++)
        {
			for (int j=1;j<=n;j++)
			{
				if (!vis[i][j]&&a[i][j]=='W')
				{
                sum++;
                dfs(i,j);
				}
			}
        }
		cout<<sum<<"\n";


	return 0;
}
