    #include <iostream>
    #include <cstring>
    #include <queue>
    #include<cstdio>
    using namespace std;
    char a[100][100];
    bool vis[100][100];
    int fang1[]={1,-1,0,0};
    int fang2[]={0,0,1,-1};
    
    struct qq{
    long long x,y;
    };
    long long m,n,x,y;
    
    long long bfs(long long x,long long y)
    {
        long long sum=0;
        queue<qq>q;
        qq q1;
        q1.x=x;
        q1.y=y;
        q.push(q1);
        while (!q.empty())
        {
            qq pp=q.front();
            sum++;
            q.pop();
            for (int i=0;i<4;i++)
            {
                long long xx=pp.x+fang1[i],yy=pp.y+fang2[i];
                if (a[xx][yy]=='.'&&xx<=n&&xx>=1&&yy<=m&&yy>=1&&!vis[xx][yy])
                {
                    vis[xx][yy]=true;
    
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
        char nnnn;
      while (cin>>m>>n&&m!=0&&n!=0)
      {
          memset(vis,false,sizeof(vis));
          for (int i=1;i<=n;i++)
          {
              for (int j=1;j<=m;j++)
              {
                  cin>>a[i][j];
                  if (a[i][j]=='@')
                  {
                      x=i;
                      y=j;
                  }
              }
              nnnn=getchar();
          }
    
          cout<<bfs(x,y)<<"\n";
      }
    
    	return 0;
    }
