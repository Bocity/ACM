#include <iostream>
    #include <cstring>
    #include <queue>
    #include<cstdio>
    using namespace std;
    int vis[301][301];
    int fang1[]={1,2,1,2,-1,-2,-1,-2};
    int fang2[]={2,1,-2,-1,2,1,-2,-1};

    struct qq{
    long long x,y;
    };
    long long m,n,x1,y1,x2,y2,L;

    long long bfs()
    {
        long long sum=0;
        queue<qq>q;
        qq q1;
        q1.x=x1;
        q1.y=y1;
        q.push(q1);
        while (!q.empty())
        {
            qq pp=q.front();
            q.pop();
            if (pp.x==x2&&pp.y==y2) return vis[pp.x][pp.y];
            for (int i=0;i<8;i++)
            {
                long long xx=pp.x+fang1[i],yy=pp.y+fang2[i];
                if (xx<L&&xx>=0&&yy<L&&yy>=0&&!vis[xx][yy])
                {
                    vis[xx][yy]=vis[pp.x][pp.y]+1;
                    qq z;
                    z.x=xx;
                    z.y=yy;
                    q.push(z);
                }
            }

        }
        return sum;
    }


    int main()
    {
       cin>>n;
       for (int i=1;i<=n;i++)
       {
           memset(vis,0,sizeof(vis));
           cin>>L;
           cin>>x1>>y1;
           cin>>x2>>y2;
           cout<<bfs()<<"\n";
       }
        return 0;
    }