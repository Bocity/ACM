#include <iostream>
#include <cstring>
#include <queue>
#include  <cstdio>
#include  <string>
using namespace std;
int d1[]={0,0,1,-1},b1,b2;
int d2[]={1,-1,0,0};
char a[200][200];
int vis[200][200]={0};
struct qq
{
    long long x,y,z=0;
};
struct cmp
{	bool	operator ()(qq &a,qq &b){
    if (vis[a.x][a.y]==vis[b.x][b.y])
	return a.z>b.z;
	else
        return vis[a.x][a.y]>vis[b.x][b.y];
}

};

long long m,n,x2,y2,z1,z2,k;

long long bfs()
{
    long long sum=0;
    priority_queue<qq,vector<qq>,cmp>q;
    qq x;
    x.x=b1;
    x.y=b2;
    q.push(x);
    while (!q.empty())
    {
        qq t=q.top();
        q.pop();
        if (a[t.x][t.y]=='a') return vis[t.x][t.y];
         for (int i=0;i<=3;i++)
         {
         	int xx=t.x+d1[i],yy=t.y+d2[i];
         	if (a[xx][yy]!='#'&&xx>=1&&xx<=n&&yy>=1&&yy<=m&&!vis[xx][yy])
         	{
                qq p;
         		vis[xx][yy]=vis[t.x][t.y]+1;

         		p.x=xx;
         		p.y=yy;
         		if (a[xx][yy]=='x'){p.z++;vis[xx][yy]++;}
         		q.push(p);
         	}
         }

    }
    return -1;

    }


int main()
{
	while(cin>>n>>m){
	    memset(vis,0,sizeof(vis));
	    for (int i=1;i<=n;i++){
	    	char x;
	    	for (int j=1;j<=m;j++)
	    	{
	    		cin>>a[i][j];
	    		if (a[i][j]=='r') {b1=i;b2=j;}

	    	}
	    	x=getchar();

	    }

	  int result=bfs();
	  if (result>=1) cout<<result<<"\n";
	  else cout<<"Poor ANGEL has to stay in the prison all his life.\n";

	}
    return 0;
}
