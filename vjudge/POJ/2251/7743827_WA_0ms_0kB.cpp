#include <iostream>
#include <cstring>
#include <queue>
#include  <cstdio>
#include  <string>
using namespace std;
char a[31][31][31];
int vis[31][31][31];
int fang1[]= {1,-1,0,0,0};
int fang2[]= {0,0,1,-1,0};
int fang3[]={0,0,0,0,1,};

struct qq
{
    long long x,y,z;
};
long long m,n,x1,y1,x2,y2,z1,z2,k;

long long bfs(long long x,long long y,long long z)
{
    long long sum=0;
    queue<qq>q;
    qq q1;
    q1.x=x;
    q1.y=y;
    q1.z=z;
    q.push(q1);

    while (!q.empty())
    {
        qq pp=q.front();
        q.pop();
        if (pp.x==x2&&pp.y==y2&&pp.z==z2) return vis[pp.x][pp.y][pp.z];
        for (int i=0; i<5; i++)
        {
            long long xx=pp.x+fang1[i],yy=pp.y+fang2[i],zz=pp.z+fang3[i];

            if (a[xx][yy][zz]!='#'&&xx<=n&&xx>=1&&yy<=m&&yy>=1&&zz<=k&&!vis[xx][yy][zz])
            {
                vis[xx][yy][zz]=vis[pp.x][pp.y][pp.z]+1;
                qq za;
                za.x=xx;
                za.y=yy;
                za.z=zz;
                q.push(za);
            }
        }

    }
    return -1;
}


int main()
{
    char nnnn;
    long long sum=0;
    while(cin>>k>>n>>m&&k&&n&&m)
    {
        memset(vis,0,sizeof(vis));
        for (int t=1;t<=k;t++)
        {
            string sps;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            {
                cin>>a[i][j][t];
                if (a[i][j][t]=='S')
                {
                x1=i;
                y1=j;
                z1=t;
                }
                if (a[i][j][t]=='E')
                {
                x2=i;
                y2=j;
                z2=t;
                }


            }
            nnnn=getchar();
        }
                    nnnn=getchar();
        }


        long long result=bfs(x1,y1,z1);
            if (result<=0) cout<<"Trapped!\n";
            else cout<<"Escaped in "<<result<<" minute(s).\n";

    }


    return 0;
}
