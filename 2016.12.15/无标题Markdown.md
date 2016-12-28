    #include <iostream>
    #include <cstring>
    #include <queue>
    #include  <cstdio>
    #include  <string>
    using namespace std;
    int vis[100000]={0};
    
    struct qq
    {
        long long x,y,z;
    };
    long long m,n,x1,y1,x2,y2,z1,z2,k;
    
    long long bfs()
    {
        long long sum=0;
        queue<int>q;
        q.push(n);
        while (!q.empty())
        {
            int t=q.front();
            q.pop();
                if (t==m) return vis[t];
                int pp=t+1;
                if (pp<=2*m+1&&pp>=0&&!vis[pp])
                {
                    vis[pp]=vis[t]+1;
                    q.push(pp);
                }
                pp=t-1;
                if (pp<=2*m+1&&pp>=0&&!vis[pp])
                {
                    vis[pp]=vis[t]+1;
                    q.push(pp);
                }
                pp=t*2;
                if (pp<=2*m+1&&pp>=0&&!vis[pp])
                {
                    vis[pp]=vis[t]+1;
                    q.push(pp);
                }
    
        }
        return -1;
    }
    
    
    int main()
    {
    cin>>n>>m;
    vis[n]=1;
    int result=bfs();
    if (result>=0) cout<<result-1;
        return 0;
    }
