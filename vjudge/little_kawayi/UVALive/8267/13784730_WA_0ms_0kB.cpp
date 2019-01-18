#include<bits/stdc++.h>
using namespace std;

#define N 10010
#define INF 100000000
struct Edge
{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};

struct ISAP
{
    int n,m,s,t;
    vector<Edge>edges;
    vector<int>G[N];
    bool vis[N];
    int d[N],cur[N];
    int p[N],num[N];//比Dinic算法多了这两个数组，p数组标记父亲结点，num数组标记距离d[i]存在几个
    void addedge(int from,int to,int cap)
    {
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        int m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    int Augumemt()
    {
        int x=t,a=INF;
        while(x!=s)//找最小的残量值
        {
            Edge&e=edges[p[x]];
            a=min(a,e.cap-e.flow);
            x=edges[p[x]].from;
        }
        x=t;
        while(x!=s)//增广
        {
            edges[p[x]].flow+=a;
            edges[p[x]^1].flow-=a;//更新反向边。
            x=edges[p[x]].from;
        }
        return a;
    }
    void bfs()//逆向进行bfs
    {
        memset(vis,0,sizeof(vis));
        queue<int>q;
        q.push(t);
        d[t]=0;
        vis[t]=1;
        while(!q.empty())
        {
            int x=q.front();q.pop();
            int len=G[x].size();
            for(int i=0;i<len;i++)
            {
                Edge&e=edges[G[x][i]];
                if(!vis[e.from]&&e.cap>e.flow)
                {
                    vis[e.from]=1;
                    d[e.from]=d[x]+1;
                    q.push(e.from);
                }
            }
        }
    }

    int Maxflow(int s,int t)//根据情况前进或者后退，走到汇点时增广
    {
        this->s=s;
        this->t=t;
        int flow=0;
        bfs();
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++)
            num[d[i]]++;
        int x=s;
        memset(cur,0,sizeof(cur));
        while(d[s]<n)
        {
            if(x==t)//走到了汇点，进行增广
            {
                flow+=Augumemt();
                x=s;//增广后回到源点
            }
            int ok=0;
            for(int i=cur[x];i<G[x].size();i++)
            {
                Edge&e=edges[G[x][i]];
                if(e.cap>e.flow&&d[x]==d[e.to]+1)
                {
                    ok=1;
                    p[e.to]=G[x][i];//记录来的时候走的边，即父边
                    cur[x]=i;
                    x=e.to;//前进
                    break;
                }
            }
            if(!ok)//走不动了，撤退
            {
                int m=n-1;//如果没有弧，那么m+1就是n，即d[i]=n
                for(int i=0;i<G[x].size();i++)
                {
                    Edge&e=edges[G[x][i]];
                    if(e.cap>e.flow)
                        m=min(m,d[e.to]);
                }
                if(--num[d[x]]==0)break;//如果走不动了，且这个距离值原来只有一个，那么s-t不连通，这就是所谓的“gap优化”
                num[d[x]=m+1]++;
                cur[x]=0;
                if(x!=s)
                    x=edges[p[x]].from;//退一步，沿着父边返回
            }
        }
        return flow;
    }
};

int main()
{
    ISAP isap;
    int T;
    cin >> T;
    while(T--) {
        int k, x, y;
        cin >> isap.n >> isap.m >> isap.s >> isap.t >> k;
        // isap.n = n;
        // isap.m = m;
        for(int i = 0; i < isap.m; i++) {
            cin >> x >> y;
            isap.addedge(x, y, 1);
            isap.addedge(y, x, 1);
        }
        // isap.s = s;
        // isap.t = t;
        int ttt = k / 3;
        if(k % 3) ttt += 1;
        cout << isap.Maxflow(isap.s, isap.t) * ttt << endl; 
    }
    // while(scanf("%d%d",&isap.n,&isap.m)!=EOF)
    // {
    //     for(int i=0;i<isap.m;i++)
    //     {
    //         int from,to,cap;
    //         scanf("%d%d%d",&from,&to,&cap);
    //         isap.addedge(from,to,cap);
    //     }
    //     scanf("%d%d",&isap.s,&isap.t);
    //     printf("%d\n",isap.Maxflow(isap.s,isap.t);)
    // }
    return 0;
}
