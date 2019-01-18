#pragma GCC optimize(2)
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
        return cost > a.cost;
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
        dis[1]=0;
        while(!q.empty())
        {
            pos=q.top();
            q.pop();
            int u=pos.nxt;
            if(vis[u])
                continue;
           // cout<<"pos : "<<u<<" "<<pos.cost<<" "<<pos.color<<endl;
            vis[u]=1;
            dis[u]=pos.cost;
//             for(int i=1;i<=n;i++)
//                cout<<dis[i]<<" ";
//            for(int i=1;i<=n;i++)
//                cout<<vis[i]<<" ";
//            cout<<endl;
            for(auto e:p[u])
            {
                if(!vis[e.to])
                {
                    if(e.color==pos.color)
                    {
                        q.push(qnode(e.to,pos.cost,pos.color));
                        //cout<<e.to<<" "<<pos.cost<<" "<<e.color<<endl;
                    }else
                    {
                        q.push(qnode(e.to,pos.cost+1,e.color));
                        //cout<<e.to<<" "<<pos.cost+1<<" "<<e.color<<endl;

                    }
                }
            }
            //cout<<endl;
        }
        if(dis[n]==INF)
            cout<<-1<<endl;
        else
            cout<<dis[n]<<endl;

    }
}

/*
4 4
1 3 2
1 2 1

2 3 2
2 4 2
*/
