#include<bits/stdc++.h>
using namespace std;
using namespace std;
const int N=1005;
const int inf=0x7fffffff;
int n,m,s,nxt[N],to[N],head[N],vis[N],
cos1[1005],
dis[N],num=0,u,v,c;
struct note{
    int to,cos1;
};
struct cmp
{
     bool operator()(int a,int b)
     {
        return dis[a]>dis[b];
    }
};
priority_queue<int,vector<int>,cmp> Q;
void push_way(int u,int v,int c)
{
    to[++num]=v;
    cos1[num]=c;
    nxt[num]=head[u];
    head[u]=num;
}
void dijkstra(int s)
{
    while(!Q.empty())
        Q.pop();
    Q.push(s);
    //vis[s]=1;
    dis[s]=0;
    while(!Q.empty())
    {
        int u=Q.top();
        Q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=nxt[i])
        {
            int v=to[i];
            if(!vis[v]&&dis[v]>dis[u]+cos1[i])
            {
                dis[v]=dis[u]+cos1[i];
                Q.push(v);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    while(cin>>n>>m&&n!=0&&m!=0)
    {
        memset(nxt,0,sizeof nxt);
        num=0;

        for(int i=0;i<m;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            push_way(x,y,z);
        }
        int ans=0;
        for(int i=1;i<=num;i++)
        {
            for(int j=1;j<=n;j++)
                dis[j]=inf;
            memset(vis,0,sizeof vis);
            int pos=cos1[i];
            cos1[i]=inf;
            dijkstra(1);
            cos1[i]=pos;
            ans=max(ans,dis[n]);

        }
        if(ans==inf)
            cout<<"inf"<<endl;
        else
            cout<<ans<<endl;

    }
}
