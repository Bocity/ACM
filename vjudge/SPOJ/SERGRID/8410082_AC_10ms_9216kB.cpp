#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#define expand(a,b,c) {prev[a][b]=p;t.x=a;t.y=b;t.z=c+1;q.push(t);;}
using namespace std;
struct point
{
    int x,y,z;
};
int m,n;
int a[600][600];
char mapp[600][600];
point prev[600][600];
bool visited[600][600];
point p,t;
int sum;
char c;
queue<point> q;

bool isok(int aa,int bb)
{
  //  cout<<"("<<aa<<","<<bb<<")";
    return (aa>0&&aa<=m&&bb>0&&bb<=n&&(a[aa][bb]!=0)&&(visited[aa][bb]==false));
}
void BFS()
{
  p.x=p.y=1;
  p.z=0;
	q.push(p);
	while (!q.empty())
	{
		p=q.front();
		q.pop();
		int &r=p.x, &c=p.y,&tt=p.z;
   //cout<<"("<<r<<","<<c<<")";
		visited[r][c]=true;
		if (r==m&&c==n)
		{
            cout<<p.z<<endl;
			return;
		}
		if (isok(r-a[r][c],c)) expand(r-a[r][c],c,tt);
		if (isok(r,c-a[r][c])) expand(r,c-a[r][c],tt);
		if (isok(r+a[r][c],c)) expand(r+a[r][c],c,tt);
		if (isok(r,c+a[r][c])) expand(r,c+a[r][c],tt);
    sum++;
	}
	cout<<"-1"<<endl;
	return;
}
int main()
{
sum=0;
cin>>m>>n;
c=getchar();
for (int i=1; i<=m;i++)
{
  for (int j=1;j<=n;j++)
  {
    c=getchar();
    a[i][j]=c-'0';
  }
    c=getchar();
}
a[m][n]=-1;
    BFS();
    return 0;
}
