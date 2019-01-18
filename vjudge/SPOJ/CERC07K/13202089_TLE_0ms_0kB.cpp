#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int o;
int u[1005]={0};
int minn;
char k[105][105];
int c[5];
int m,n;
int step;
int r[4]={0,1,-1,0};
int t[4]={1,0,0,-1};
void dfs(int a,int b)
{
	if(a>=m||a<0||b>=n||b<0)
	return ;
	if(k[a][b]=='#')
	return ;
	if(k[a][b]=='R'&&c[3]==0)
	return ;
	if(k[a][b]=='B'&&c[1]==0)
	return ;
	if(k[a][b]=='Y'&&c[2]==0)
	return ;
	if(k[a][b]=='G'&&c[4]==0)
	return ;
	if(step==minn)
	return;
	if(k[a][b]=='r')
	c[3]++;
	if(k[a][b]=='b')
	c[1]++;
	if(k[a][b]=='y')
	c[2]++;
	if(k[a][b]=='g')
	c[4]++;
	for(int i=0;i<4;i++)
	{
		a+=r[i];
		b+=t[i];
		if(k[a][b]=='X')
	{
		step++;
//		minn=min(step,minn);
//		printf("%d\n",step);
		return ;
	}
		if((a<m&&a>=0&&b<n&&b>=0)&&(k[a][b]=='r'||k[a][b]=='b'||k[a][b]=='y'||k[a][b]=='g'||k[a][b]=='.'))
		{
			step++;
		dfs(a,b);
	}
	}
}
int main()
{
	while(scanf("%d%d",&m,&n)&&m+n)
	{
		o=0;
		minn=10000;
		for(int i=0;i<5;i++)
		c[i]=0;
		for(int i=0;i<m;i++)
		scanf("%s",k[i]);
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(k[i][j]=='*')
				{
					step=0;
				    dfs(i,j);
				    u[o]=step;
				    o++;
//				    cout<<step<<endl;
				}
			}
		}
		sort(u,u+o-1);
		if(u[0]>=10000)
		printf("Escape possible in %d steps.\n",u[0]);
		else
		printf("The poor student is trapped!\n");
	}
	return 0;
}
