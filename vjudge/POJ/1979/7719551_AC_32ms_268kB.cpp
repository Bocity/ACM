#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
char a[100][100];
bool vis[100][100]={0};
int n,m,sum=0,x,y;
void dfs(int x,int y)
{
	if (vis[x][y]) return ;
	vis[x][y]=true;
	sum++;
	if (y+1<=n && a[x][y+1]=='.') dfs(x,y+1);
	if (x+1<=m && a[x+1][y]=='.') dfs(x+1,y);
	if (y-1>=1 && a[x][y-1]=='.') dfs(x,y-1);
	if (x-1>=1 && a[x-1][y]=='.') dfs(x-1,y);
	return ;
}
int main()
{
	while(cin >> n >> m && m!=0 && n!=0 )
	{
		sum=0;
		memset(vis,false,sizeof(vis));
		for (int i=1;i<=m;i++)
        {
			for (int j=1;j<=n;j++)
			{
				cin>>a[i][j];
				if (a[i][j] =='@')
					{x=i;
                    y=j;}
			}
			getchar();
        }
		dfs(x,y);
		cout<<sum<<"\n";

	}

	return 0;
}
