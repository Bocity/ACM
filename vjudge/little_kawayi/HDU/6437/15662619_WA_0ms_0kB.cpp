/*
最小费用最大流，求最大费用只需要取相反数，结果取相反数即可。
点的总数为 N，点的编号 0~N-1
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10000;
const int MAXM = 100000;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int to,next,cap,flow,cost;
} edge[MAXM];
int head[MAXN],tol;
int pre[MAXN],dis[MAXN];
bool vis[MAXN];
int N;//节点总个数，节点编号从0~N-1
void init(int n)
{
    N = n;
    tol = 0;
    memset(head,-1,sizeof (head));
}
void addedge (int u,int v,int cap,int cost)
{
    edge[tol].to = v;
    edge[tol].cap = cap;
    edge[tol].cost = cost;
    edge[tol].flow = 0;
    edge[tol].next = head[u];
    head[u] = tol++;
    edge[tol].to = u;
    edge[tol].cap = 0;
    edge[tol].cost = -cost;
    edge[tol].flow = 0;
    edge[tol].next = head[v];
    head[v] = tol++;
}
bool spfa(int s,int t)
{
    queue<int>q;
    for(int i = 0; i < N; i++)
    {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = head[u]; i !=  -1; i = edge[i]. next)
        {
            int v = edge[i]. to;
            if(edge[i].cap > edge[i].flow &&
                    dis[v] > dis[u] + edge[i]. cost )
            {
                dis[v] = dis[u] + edge[i]. cost;
                pre[v] = i;
                if(!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if(pre[t] == -1)return false;
    else return true;
}
//返回的是最大流，cost存的是最小费用
int minCostMaxflow(int s,int t,int &cost)
{
    int flow = 0;
    cost = 0;
    while(spfa(s,t))
    {
        int Min = INF;
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])
        {
            if(Min > edge[i].cap - edge[i]. flow)
                Min = edge[i].cap - edge[i].flow;
        }
        for(int i = pre[t]; i != -1; i = pre[edge[i^1].to])
        {
            edge[i].flow += Min;
            edge[i^1].flow -= Min;
            cost += edge[i]. cost * Min;
        }
        flow += Min;
    }
    return flow;
}
int s,t,s1;
int n,m,k,w;
struct node
{
    int s,t,value,tp;
}pos[205];
int main()
{
    int st;
    cin>>st;
    while(st--)
    {
        cin>>n>>m>>k>>w;
        for(int i=1;i<=m;i++)
        {
            cin>>pos[i].s>>pos[i].t>>pos[i].value>>pos[i].tp;
        }
        init(m+3);
        s=0,s1=m+1,t=m+2;
        addedge(s,s1,k,0);
//        cout<<s<<" "<<s1<<" "<<k<<" "<<0<<endl;
        for(int i=1;i<=m;i++)
        {
            addedge(s1,i,1,-pos[i].value);
//                    cout<<s1<<" "<<i<<" "<<1<<" "<<-pos[i].value<<endl;

            addedge(i,t,1,0);
//                    cout<<i<<" "<<t<<" "<<1<<" "<<0<<endl;

            for(int j=1;j<=m;j++)
            {
                if(pos[i].t<=pos[j].s)
                {
                    if(pos[i].tp==pos[j].tp)
                    {
                        addedge(i,j,1,-(pos[j].value-w));
//                                cout<<i<<" "<<j<<" "<<1<<" "<<-(pos[j].value-w)<<endl;

                    }else
                    {
                        addedge(i,j,1,-pos[j].value);
//                        cout<<i<<" "<<j<<" "<<1<<" "<<-pos[j].value<<endl;
                    }
                }
            }
        }
        int cost;

        minCostMaxflow(s,t,cost);
        cout<<-cost<<endl;
    }
}
/*
2
10 3 3 10
1 5 1000 0
5 10 1000 1
3 9 10 0
10 3 1 10
1 5 1000 0
5 10 1000 0
3 9 10 0
*/
