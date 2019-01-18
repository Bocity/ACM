#include<bits/stdc++.h>
using namespace std;
class B
{
#define N 2005
private:
    bool g[N][N];
    int UN,VN;
    int link[N];
    bool vis[N];

    bool dfs(int u)
    {
        for(int v=1; v<=VN; v++)
        {
            if(g[u][v]&&!vis[v])
            {
                vis[v]=1;
                if(link[v]==-1||dfs(link[v]))
                {
                    link[v]=u;
                    return 1;
                }
            }
        }
        return 0;
    }
public:
    void init(int u,int v)
    {
        UN=u;
        VN=v;
        memset(g,0,sizeof g);
    }
    void addegde(int u,int v)
    {
        g[u][v]=1;
    }
    int hun()
    {
        int ans=0;
        memset(link,-1,sizeof link);
        for(int u=1; u<=UN; u++)
        {
            memset(vis,0,sizeof vis);
            if(dfs(u))
                ans++;
        }
        return ans;
    }
} solver;
int main()
{

    int n;
    cin>>n;
    solver.init(n,n);
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        for(int j=1; j<=x; j++)
        {
            int q;
            cin>>q;
            solver.addegde(i,q+1);
        }
    }
    //cout<<solver.hun()<<endl;
    cout<<n-solver.hun()<<endl;

}

