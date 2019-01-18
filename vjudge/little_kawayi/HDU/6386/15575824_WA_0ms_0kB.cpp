#include<bits/stdc++.h>
using namespace std;
const int INF=0x7fffffff;
const int maxn=1e5+10;
struct Edge
{
    int to,color;
    Edge(int x,int y):to(x),color(y){};
};
struct qnode
{
    int nxt;
    int cost;
    int color;
    qnode(){};
    qnode(int x,int y,int z):nxt(x),cost(y),color(z){};
    bool operator < (const qnode &a)const
    {
        return cost<a.cost;
    }
};
bool vis[maxn];
int dis[maxn];
vector<Edge>p[maxn];
int n,m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n>>m)
    {
        for(int i=0;i<maxn;i++)
            p[i].clear(),dis[i]=INF;

        int x,y,z;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y>>z;
            p[x].push_back(Edge(y,z));
            p[y].push_back(Edge(x,z));
        }
        memset(vis,0,sizeof vis);
        priority_queue<qnode> q;
        q.push(qnode(1,0,0));
        qnode pos;
        vis[1]=0;
        while(!q.empty())
        {
            pos=q.top();
            q.pop();
            vis[pos.nxt]=1;
            dis[pos.nxt]=pos.cost;
            //cout<<pos.nxt<<" "<<pos.cost<<" "<<pos.color<<endl;
            for(auto e:p[pos.nxt])
            {
                if(!vis[e.to])
                {
                    if(e.color==pos.color)
                    {
                        q.push(qnode(e.to,pos.cost,pos.color));
                    }else
                    {
                        q.push(qnode(e.to,pos.cost+1,pos.color));
                    }
                }
            }
        }
        if(dis[n]==INF)
            cout<<-1<<endl;
        else
            cout<<dis[n]<<endl;

    }
}
