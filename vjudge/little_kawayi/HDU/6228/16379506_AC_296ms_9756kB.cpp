#include<bits/stdc++.h>

using namespace std;

const int MAX=2e5+10;

vector<int> G[MAX];
struct node
{
    int l,r;
}edge[MAX];
int P[MAX];
int sz[MAX];
void inputTree(int n)
{
    int u, v;

    for (int i = 0; i < n-1; ++i)
    {
        cin >> u >> v;
        edge[i].l=u,edge[i].r=v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
}

void dfs(int u, int fa)
{
    int d = G[u].size();

    for (int i = 0; i < d; ++i)
    {
        int v = G[u][i];
        if (v != fa)
            dfs(v, P[v] = u);
    }
}
void DFS(int x)
{
    if(G[x].size()==0)
    {
        sz[x]=1;
        return ;
    }
    for(auto e:G[x])
    {
        DFS(e);
        sz[x]+=sz[e];
    }
    sz[x]++;
    return;
}
void init()
{
    for(int i=0;i<MAX;i++)
        G[i].clear();
    memset(P,0,sizeof P);
    memset(sz,0,sizeof sz);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int k;
        int root;
        cin >> n>>k;
        init();
        inputTree(n);
        for(int i=1; i<=n; i++)
        {
            if(G[i].size()==1)
            {
                root=i;
                break;
            }
        }
        P[root]=-1;
        dfs(root, P[root]);
        for(int i=1;i<=n;i++)
        {
            G[i].clear();
        }
        for(int i=1;i<=n;i++)
            G[P[i]].push_back(i);
        DFS(root);
        int ans=0;

        for(int i=0;i<n-1;i++)
        {
            int u,v;
            if(edge[i].l==P[edge[i].r])
            {
                u=edge[i].l;
                v=edge[i].r;
            }else
            {
                v=edge[i].l;
                u=edge[i].r;
            }
            if(sz[v]>=k&&(n-sz[v])>=k)
                ans++;
        }
        cout<<ans<<endl;
    }


    return 0;
}
