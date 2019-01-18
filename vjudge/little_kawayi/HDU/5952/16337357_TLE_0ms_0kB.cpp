#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int use[maxn];
int pos[maxn];
int mapp[maxn][maxn];
int n,m,s;
long long ans=0;
bool dfs(int nowx,int dep)
{
    if(dep==s)
    {
        ans++;
        return 0 ;
    }
    memset(pos,0,sizeof pos);
    for(int i=nowx+1;i<=n;i++)
    {
        if(mapp[nowx][i]==0)
        {
            if(mapp[nowx][i]==0&&use[i]==1)
                pos[i]=1;
            use[i]=0;
        }
    }
    for(int i=nowx+1;i<=n;i++)
    {
        if(use[i]==1)
            dfs(i,dep+1);
    }
    for(int i=nowx+1;i<=n;i++)
        if(pos[i]==1)
            use[i]=1;
}
void init()
{
    for(int i=1;i<maxn;i++)
        use[i]=1;
    memset(mapp,0,sizeof mapp);
    ans=0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        init();
        cin>>n>>m>>s;
        int x,y;
        for(int i=0;i<m;i++)
        {
            cin>>x>>y;
            mapp[x][y]=1;
            mapp[y][x]=1;
        }
        for(int i=1;i<=n;i++)
        {
            dfs(i,1);
        }
        cout<<ans<<endl;
    }
}
